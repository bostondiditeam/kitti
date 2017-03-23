#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <string.h>
#include <cstring>
#include <unistd.h>
#include <sstream>
#include <iomanip>  

#include <pcl/visualization/cloud_viewer.h>
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>

using namespace std;

int delay = 100000; // delay between successive LiDAR frames in micro-seconds

void 
viewerOneOff (pcl::visualization::PCLVisualizer& viewer)
{
    viewer.setBackgroundColor (0, 0, 0);
    viewer.addCoordinateSystem (10);
    // viewer.setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "cloud");
    // std::cout << "i only run once" << std::endl;
    
}

void colorize_point_cloud(double curr_intensity, pcl::PointXYZRGBA *sample)
{	
	// This function adds RGB color to points in the point cloud based on each point's refelctivity.
	// Blue: Low reflectivity, Yellow/Green: Medium reflectivity, Red: High reflectivity
	
	curr_intensity = curr_intensity * 255;
	
    double intensity_range = 255; //any intensity value above this value will be red
    double wavelength;
    double min_wavelength = 470; // used to discard overtly blue and purple points that are invisible due to the black background

    if(curr_intensity <= intensity_range)
        wavelength = curr_intensity / intensity_range * (780 - min_wavelength) + min_wavelength;
    else
        wavelength = 780;

    if((wavelength >= 380) && (wavelength < 440)){
        sample->r = (-(wavelength - 440) / (440 - 380))*255;
        sample->g = 0;
        sample->b = 255;

    }else if((wavelength >= 440) && (wavelength<490)){
        sample->r = 0;
        sample->g = ((wavelength - 440) / (490 - 440))*255;
        sample->b = 255;

    }else if((wavelength >= 490) && (wavelength<510)){
        sample->r = 0;
        sample->g = 255;
        sample->b = (-(wavelength - 510) / (510 - 490))*255;

    }else if((wavelength >= 510) && (wavelength<580)){
        sample->r = ((wavelength - 510) / (580 - 510))*255;
        sample->g = 255;
        sample->b = 0;

    }else if((wavelength >= 580) && (wavelength<645)){
        sample->r = 255;
        sample->g = (-(wavelength - 645) / (645 - 580))*255;
        sample->b = 0;

    }else if((wavelength >= 645) && (wavelength < 781)){
        sample->r = 255;
        sample->g = 0;
        sample->b = 0;
    }else{
        sample->r = 0;
        sample->g = 0;
        sample->b = 0;
    }

    sample->a = 255;
}

int main()
{  

	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGBA>);
	pcl::visualization::CloudViewer viewer("Cloud Viewer");
	    

	viewer.runOnVisualizationThreadOnce (viewerOneOff);

	// load point cloud
	FILE *stream;
	int mFrameCounter = 0;
	
	string mVeloPath;
	mVeloPath  = "2011_09_26_drive_0001_sync/velodyne_points/data/";

	while (!viewer.wasStopped ())
	{	
		int32_t num = 1000000;
		float *data = (float*)malloc(num*sizeof(float));

		float *px = data+0;
		float *py = data+1;
		float *pz = data+2;
		float *pr = data+3;

		ostringstream veloFileName;
    	veloFileName << setfill('0') << setw(10) << mFrameCounter << ".bin";
    	mFrameCounter++;

    	string full_velo_path = mVeloPath + veloFileName.str();

		// const char* x = file_path[ctr].c_str();
		const char* x = full_velo_path.c_str();
		stream = fopen (x, "rb");

		if(stream == NULL){
			cout << x << " not found. Ensure that the file path is correct." << endl;
			return 0;
		}

		num = fread(data,sizeof(float),num,stream)/4;
		for (int32_t i=0; i<num; i++) {

		  	pcl::PointXYZRGBA sample;
		  	sample.x = *px;
		  	sample.y = *py;
		  	sample.z = *pz;

		  	colorize_point_cloud(*pr, &sample);

		    cloud->points.push_back(sample);
		    px+=4; py+=4; pz+=4; pr+=4;
		}
		// cout << num << endl;
		fclose(stream);
		//blocks until the cloud is actually rendered
 		viewer.showCloud(cloud);

 		usleep(delay);

 		cloud->points.clear();

		delete data;
	
	}

	return 0;  
}