import rospy
from demo_pkg.srv import AddTwoInts, AddTwoIntsResponse

def add_two_ints_client(x,y):
    rospy.init_mode("client")

    rospy.wait_for_service("add_two_ints_python")
    rate = rospy.Rate(1)

    while not rospy.is_shutdown()
        try:
            add_two_ints = rospy.ServiceProxy('add_two_ints_python', AddTwoInts)
            response = add_two_ints(x,y)

            rospy.loginfo(response.magnitude)
            rate.sleep()
        except rospy.ServiceException as e:
            print("Sercive call failed %s", e)

if __name__ == '__main__':
    add_two_ints_client(12,10)