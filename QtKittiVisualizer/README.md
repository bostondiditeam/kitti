QtKittiVisualizer
=================
Description
-----------
This is a Qt based GUI application to visualize Velodyne LiDAR data from the Kitty data set along with its associated 3D bounding boxes.

Requirements
-----------
Qt 4
PCL 1.7 (sudo apt-get install build-essential cmake libpcl1.7 libpcl-dev pcl-tools)
CMake 2.8
Boost 1.54
Check CMakeLists.txt for further requirements

Compilation Instructions
-----------
Run cmake .
Run make

To Run
-----------
Run ./qt-kitti-visualizer
Modify the file path to .bin Velodyne files in KittiConfig.cpp if the application cannot find the file during run time.


Description
-----------

The **QtKittiVisualizer** allows viewing the 3D point clouds and bounding boxes of the [raw KITTI data sets](http://www.cvlibs.net/datasets/kitti/raw_data.php).  It is a tool based on *Qt*, the *PCL* and the *VTK*.

It includes the *C++* part of the [raw data development kit](http://kitti.is.tue.mpg.de/kitti/devkit_raw_data.zip) provided on the [official KITTI website](http://www.cvlibs.net/datasets/kitti/).

License
-------

The new parts of the software are licensed under the [Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0).


