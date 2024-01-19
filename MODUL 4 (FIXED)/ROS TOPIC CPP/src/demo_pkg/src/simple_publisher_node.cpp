#include "ros/ros.h"
#include "demo_pkg/Pesan.h"

int main(int argc, char ** argv){
    ros::init(argc,argv,"simple_publisher_noce_cpp");

    ros::NodeHandle nh;
    
    ros::Publisher data_publisher = nh.advertise<demo_pkg::Pesan>("topik_utama", 1000);

    ros::Rate loop_rate(1);

    while(ros::ok()){
        demo_pkg::Pesan pesanMauDikirim;

        pesanMauDikirim.usia = 18;
        pesanMauDikirim.tinggi = 173.2;
        pesanMauDikirim.nama = "Abrar Abhirama Widyadhana";
        pesanMauDikirim.kehadiran = true;

        ROS_INFO("Usia : %ld",pesanMauDikirim.usia);
        ROS_INFO("Tinggi: %lf",pesanMauDikirim.tinggi);
        ROS_INFO("Nama: %s",pesanMauDikirim.nama.c_str());
        ROS_INFO("Kehadiran: %s",pesanMauDikirim.kehadiran ? "true" : "false");

        data_publisher.publish(pesanMauDikirim);

        ros::spinOnce();
        loop_rate.sleep();
    }


    return 0;
}