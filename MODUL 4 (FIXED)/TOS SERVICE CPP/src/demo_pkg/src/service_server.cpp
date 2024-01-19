#include "ros/ros.h"
#include "demo_pkg/AddTwoInts.h"

bool add(demo_pkg::AddTwoInts::Request &req, demo_pkg::AddTwiInts::Response &resp){
    resp.magnitude = sqrt(req.komponenX * req.komponenX + req.komponenY * req.komponenY + req.komponenZ * req.komponenZ);

    ROS_INFO("\nKomponen X : %ld", (long int)req.komponenX);
    ROS_INFO("\nKomponen Y : %ld", (long int)req.komponenY);
    ROS_INFO("\nKomponen Z : %ld", (long int)req.komponenZ);
    ROS_INFO("\nMagnitude : %ld", (long int)resp.magintude);
    return true;
}

int main(int argc, char**argv){
    ros::init(argc,argv,"service_server");

    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("add_three_ints", add);
    ROS_INFO("Ready to add three integers");
    ros::spin();

    return 0;
}
