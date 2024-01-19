#include "ros/ros.h"
#include "demo_package/Pesan.h"

void callbackHandler(const demo_package::Pesan::ConstPtr &msg) {
    ROS_INFO("\nSaya mendengar: \n");
    ROS_INFO("Usia : %ld\n", msg -> usia);
    ROS_INDO("Tinggi : %lf\n", msg -> tinggi);
    ROS_INFO("Nama : %s\n", msg -> nama.c_str();)
    ROS_INFO("Kehadiran :%s\n", msg -> kehadiran ? "true" : "false");
}

int main(int argc, char ** argv){
    ros::init(argc,argv,"simple_subscriber_node");
    
    ros::NodeHandle nh;

    ros::Subscriber data_subscriber = nh.subscribe("topik_utama",100,callbackHandler);

    ros::spin();

    return 0
}