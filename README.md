# kitti
Exploratory Findings for the KITTI Vision Benchmark Suite


KITTI Vision Benchmark Suite site:  http://www.cvlibs.net/datasets/kitti/eval_object.php

### Overview

[Are we ready for Autonomous Driving? The KITTI Vision Benchmark Suite](http://www.cvlibs.net/publications/Geiger2012CVPR.pdf)

Excerpt from the abstract:
~~~~
Results from state-of-the-art algorithms reveal that methods ranking high on established datasets
such as Middlebury perform below average when being moved outside the laboratory to the real world.
Our [Karlsruhe Institute of Technology] goal is to reduce this bias by providing challenging benchmarks with novel difficulties to
the computer vision community.
~~~~~

### Images

There are four sets of images:
- left color images of object data set (12 GB)
- right color images, if you want to use stereo information (12 GB)
- the 3 temporally preceding frames (left color) (36 GB)
- the 3 temporally preceding frames (right color) (36 GB)

Each is comprised of training and testing sets.  The training set has 7,480 images, while the testing
set has 7,517 images.  Because of the amount of disk space these images consume, we are not able to
include them all in this repository.  They can be downloaded from
http://www.cvlibs.net/datasets/kitti/eval_object.php.

Please see image samples [here](images.md). The image files are in the [images](./images)
directory.

#### Dimensions

The images appear to have varying dimensions.  However, dimensions for a single scene (left, right,
3 previous left, 3 previous right) are consistent. A quick sampling of images provided the following
dimensions (in pixels):
- 000189.png: 1224 x 370
- 000274.png: 1242 x 375
- 001603.png: 1241 x 376
- 001822.png: 1238 x 374

#### Labels

Labels for the training set can be found in the
[zip_files](https://github.com/bostondidi/kitti/tree/master/zip_files) directory.  A sample is
provided with an image sample at [here](images.md#labels).

#### Bounding Boxes
The bounding boxes are defined by the bbox values from the data.  See the [images.md](images.md#labels) writeup for more detail.
See [2D_BBox.ipynb](tools/2D_BBox.ipynb) for a demonstration.

### Performace Metrics

#### Easy/Moderate/Hard difficulty

Excerpt from [the object detection eval page](http://www.cvlibs.net/datasets/kitti/eval_object.php)
~~~~
Difficulties are defined as follows:
- Easy: Min. bounding box height: 40 Px, Max. occlusion level: Fully visible, Max. truncation: 15 %
- Moderate: Min. bounding box height: 25 Px, Max. occlusion level: Partly occluded, Max. truncation: 30 %
- Hard: Min. bounding box height: 25 Px, Max. occlusion level: Difficult to see, Max. truncation: 50 %
All methods are ranked based on the moderately difficult results.
~~~~

That said, the moderate difficulty is of interest.
Constraints for a record to be considered moderate difficulty:
- The *occluded* column is 0 or 1.
- The *truncated* has a max value of 0.3.
- The max value of the bounding box height is 25.0 (px).
  - The bounding box height is the difference between the *top* and *bottom* columns.
  - Being pixel values, you'd think these should be integers. Don't be fooled by the decimal values.

An example of some data records with these columns can be found in [images.md](images.md#labels).

We can use these constraints to ignore certain data records when measuring the performance of the model.

### Velodyne Point Clouds


### Object Development Kit
