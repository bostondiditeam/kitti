#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <string.h>
#include <cstring>
#include <unistd.h>

#include <pcl/visualization/cloud_viewer.h>
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>

using namespace std;

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
	// double curr_intensity_II = curr_intensity;
	curr_intensity = curr_intensity * 255;
	// cout << curr_intensity_II << ", " << curr_intensity << endl;
	// cout << curr_intensity_II << endl;

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

	// For now, the filenames are input manually
	int num_files = 40;
	string file_path[num_files];
	file_path[0] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000000.bin";
	file_path[1] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000001.bin";
	file_path[2] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000002.bin";
	file_path[3] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000003.bin";
	file_path[4] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000004.bin";
	file_path[5] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000005.bin";
	file_path[6] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000006.bin";
	file_path[7] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000007.bin";
	file_path[8] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000008.bin";
	file_path[9] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000009.bin";
	file_path[10] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000010.bin";
	file_path[11] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000011.bin";
	file_path[12] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000012.bin";
	file_path[13] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000013.bin";
	file_path[14] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000014.bin";
	file_path[15] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000015.bin";
	file_path[16] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000016.bin";
	file_path[17] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000017.bin";
	file_path[18] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000018.bin";
	file_path[19] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000019.bin";
	file_path[20] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000020.bin";
	file_path[21] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000021.bin";
	file_path[22] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000022.bin";
	file_path[23] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000023.bin";
	file_path[24] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000024.bin";
	file_path[25] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000025.bin";
	file_path[26] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000026.bin";
	file_path[27] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000027.bin";
	file_path[28] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000028.bin";
	file_path[29] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000029.bin";
	file_path[30] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000030.bin";
	file_path[31] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000031.bin";
	file_path[32] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000032.bin";
	file_path[33] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000033.bin";
	file_path[34] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000034.bin";
	file_path[35] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000035.bin";
	file_path[36] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000036.bin";
	file_path[37] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000037.bin";
	file_path[38] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000038.bin";
	file_path[39] = "2011_09_26_drive_0001_sync/velodyne_points/data/0000000039.bin";

	// load point cloud
	int ctr = 0;
	FILE *stream;
	
	while (!viewer.wasStopped ())
	{	
		int32_t num = 1000000;
		float *data = (float*)malloc(num*sizeof(float));

		float *px = data+0;
		float *py = data+1;
		float *pz = data+2;
		float *pr = data+3;

		const char* x = file_path[ctr].c_str();
		stream = fopen (x, "rb");

		if(stream == NULL){
			cout << file_path[ctr] << " not found. Ensure that the file path is correct." << endl;
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

 		usleep(300000);

 		cloud->points.clear();

 		// viewer.showCloud(cloud);
		//you can also do cool processing here
		//FIXME: Note that this is running in a separate thread from viewerPsycho
		//and you should guard against race conditions yourself...
		ctr++;

		delete data;
		// delete px;
		// delete py;
		// delete pz;
		// delete pr;
		// cout << ctr << endl;
		if(ctr == num_files){
			cout << "Exiting" << endl;
			// while(1){

			// }
			return 0;
		}
		
	}


	return 0;  
}