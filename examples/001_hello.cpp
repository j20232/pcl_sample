#include <pcl/io/io.h>
#include <pcl/io/obj_io.h>
#include <pcl/visualization/cloud_viewer.h>
#include <vtkAutoInit.h>

#include <iostream>

VTK_MODULE_INIT(vtkRenderingOpenGL2);

int user_data;

void viewerOneOff(pcl::visualization::PCLVisualizer& viewer) {
    viewer.setBackgroundColor(0.5, 0.2, 0.6);
    pcl::PointXYZ o;
    o.x = 1.0;
    o.y = 0.0;
    o.z = 0.0;
    viewer.addSphere(o, 0.25, "sphere", 0);
    std::cout << "This method is called once" << std::endl;
}

void viewerPsycho(pcl::visualization::PCLVisualizer& viewer) {
    static unsigned cnt = 0;
    std::stringstream ss;
    ss << "Once per viewer loop: " << cnt++;
    viewer.removeShape("text", 0);
    viewer.addText(ss.str(), 200, 300, "text", 0);
    user_data++;  // dirty
}

int main() {
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud(
        new pcl::PointCloud<pcl::PointXYZRGBA>);
    pcl::io::loadOBJFile("../assets/unchan_pink.obj", *cloud);
    pcl::visualization::CloudViewer viewer("Cloud Viewer");
    viewer.showCloud(cloud);
    viewer.runOnVisualizationThreadOnce(viewerOneOff);
    viewer.runOnVisualizationThread(viewerPsycho);
    while (!viewer.wasStopped()) {
        user_data++;
    }
    return 0;
}
