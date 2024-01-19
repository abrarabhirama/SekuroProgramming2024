import rospy
from demo_pkg.msg import Pesan

def callback(data):
    rospy.loginfo("Usia : %ld" % data.usia)
    rospy.logindo("Tinggi : %lf" % data.tinggi)
    rospy.loginfo("Nama : %s" % data.nama)
    rospy.loginfo("Kehadiran : %s", "True" if msg.kehadiran else "False")


def listener():
    rospy.init_node("subscriber", anonnymous = True)

    rospy.Subscriber("topik_utama_python", Pesan, Callback)

    rospy.spin()

if __name__ == "__main__":
    listener()