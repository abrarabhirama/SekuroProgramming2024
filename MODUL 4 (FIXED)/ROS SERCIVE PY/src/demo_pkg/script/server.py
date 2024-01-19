import rospy
from demo_pkg.srv import AddTwoInts, AddTwoIntsResponse
from math import sqrt

def penjumlahan(req):
    resp = AddTwoIntsResponse()
    resp.magnitude = sqrt(req.komponenX**2 + req.komponenY**2 + req.komponenZ**2)

    rospy.loginfo("Komponen X : %d", req.komponenX)
    rospy.loginfo("Komponen Y : %d", req.komponenY)
    rospy.loginfo("Komponen Z : %d", req.komponenZ)
    rospy.loginfo("Magnitude : %d", resp.magnitude)
    
    return resp

def main():
    rospy.init_node('service_server')
    service = rospy.Service('add_three_ints', AddTwoInts, penjumlahan)
    rospy.loginfo("Ready to add three integers")
    rospy.spin()

if __name__ == '__main__':
    main()