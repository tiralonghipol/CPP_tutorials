#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

int user_data;

void viewerOneOff(pcl::visualization::PCLVisualizer &viewer)
{
  viewer.setBackgroundColor(1.0, 0.5, 1.0);
  pcl::PointXYZ o;
  o.x = 1.0;
  o.y = 0;
  o.z = 0;
  viewer.addSphere(o, 0.25, "sphere", 0);
  std::cout << "i only run once" << std::endl;
}

void viewerPsycho(pcl::visualization::PCLVisualizer &viewer)
{
  static unsigned count = 0;
  std::stringstream ss;
  ss << "Once per viewer loop: " << count++;
  viewer.removeShape("text", 0);
  viewer.addText(ss.str(), 200, 300, "text", 0);

  //FIXME: possible race condition here:
  user_data++;
}

int main(int argc, char **argv)
{
  char *choice = argv[1];

  pcl::PointCloud<pcl::PointXYZ> cloud;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloudP;
  // Fill in the cloud data
  cloud.width = 200;
  cloud.height = 1;
  cloud.is_dense = false;
  cloud.points.resize(cloud.width * cloud.height);

  for (std::size_t i = 0; i < cloud.points.size(); ++i)
  {
    cloud.points[i].x = 1024 * rand() / (RAND_MAX + 1.0f);
    cloud.points[i].y = 1024 * rand() / (RAND_MAX + 1.0f);
    cloud.points[i].z = 1024 * rand() / (RAND_MAX + 1.0f);
    // default component is zero
  }

  if (strcmp(choice, "1") == 0)
  {
    // 1) Write to file and terminal print
    pcl::io::savePCDFileASCII("/home/pol/CPP_tutorials/11_Pcl/output/test_pcd.pcd", cloud);
    std::cerr << "Saved " << cloud.points.size() << " data points to test_pcd.pcd" << std::endl;
    for (std::size_t i = 0; i < cloud.points.size(); ++i)
      std::cerr << "    " << cloud.points[i].x << " " << cloud.points[i].y << " " << cloud.points[i].z << std::endl;
  }

  else if (strcmp(choice, "2") == 0)

  {
    // 2) visualize the cloud

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile("/home/pol/CPP_tutorials/11_Pcl/output/test_pcd.pcd", *cloud);

    pcl::visualization::CloudViewer viewer("Cloud Viewer");

    //blocks until the cloud is actually rendered
    viewer.showCloud(cloud);

    //use the following functions to get access to the underlying more advanced/powerful
    //PCLVisualizer

    while (!viewer.wasStopped())
    {
      //you can also do cool processing here
      //FIXME: Note that this is running in a separate thread from viewerPsycho
      //and you should guard against race conditions yourself...
      user_data++;
    }
  }

  return (0);
}
