import rospy
from demo_pkg.msg import Pesan

def talker():
    message_pub = rospy.Publisher("tpik_utama_python", Pesan, queue_size =10)

    rospy.init_node('publisher',annonymous = True)

    rate = rospy.Rate(1)

    while not rospy.is_shutdown()
        
        dataVariabel = Pesan()

        dataVariabel.usia = 18
        dataVariabel.tinggi = 173.6
        dataVariabel.nama = "Abrar Abhirama Widyadhana"
        dataVariabel.kehadiran = True 

        rospy.loginfo("\nUsia : %ld" % dataVariabel.usia)
        rospy.loginfo("Tinggi : %lf" % dataVaiabel.tinggi)
        rospy.loginfo("Nama : %s" % dataVariabel.nama)
        rospy.loginfo("Kehadiran : %s" % ("True" if dataVariabel.kehadiran else "False"))

        message_pub.publish(dataVariabel)

        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
        