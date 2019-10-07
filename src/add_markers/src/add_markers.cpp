#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <std_msgs/String.h>

visualization_msgs::Marker marker;
ros::Publisher marker_pub;

void goalCallback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("Goal is %s", msg->data.c_str());
  if (msg->data == "loc1") {
    ROS_INFO("loc1");
    
    marker.pose.position.x = 4;
    marker.pose.position.y = 2;
    marker.action = visualization_msgs::Marker::ADD;
    marker_pub.publish(marker);

  } else if (msg->data == "invisible") {
    ROS_INFO("invisible");

    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);

  } else if (msg->data == "loc2") {
    ROS_INFO("loc2");

    marker.pose.position.x = -3;
    marker.pose.position.y = 0;
    marker.action = visualization_msgs::Marker::ADD;
    marker_pub.publish(marker);
  } else {
    ROS_INFO("else");
  }
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  ros::Subscriber sub = n.subscribe("goal", 1000, goalCallback);

  uint32_t shape = visualization_msgs::Marker::CUBE;

  marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();
  marker.ns = "basic_shapes";
  marker.id = 0;
  marker.type = shape;

  marker.pose.position.x = 5;
  marker.pose.position.y = 3;
  marker.pose.position.z = 0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = 0.5;
  marker.scale.y = 0.5;
  marker.scale.z = 0.5;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;

  marker.lifetime = ros::Duration();

  ros::spin();

//  // Set our initial shape type to be a cube
//  uint32_t shape = visualization_msgs::Marker::CUBE;
//
//  while (ros::ok())
//  {
//    visualization_msgs::Marker marker;
//    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
//    marker.header.frame_id = "map";
//    marker.header.stamp = ros::Time::now();
//
//    // Set the namespace and id for this marker.  This serves to create a unique ID
//    // Any marker sent with the same namespace and id will overwrite the old one
//    marker.ns = "basic_shapes";
//    marker.id = 0;
//
//    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
//    marker.type = shape;
//
//    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
//    marker.action = visualization_msgs::Marker::ADD;
//
//    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
//    marker.pose.position.x = 5;
//    marker.pose.position.y = 3;
//    marker.pose.position.z = 0;
//    marker.pose.orientation.x = 0.0;
//    marker.pose.orientation.y = 0.0;
//    marker.pose.orientation.z = 0.0;
//    marker.pose.orientation.w = 1.0;
//
//    // Set the scale of the marker -- 1x1x1 here means 1m on a side
//    marker.scale.x = 0.5;
//    marker.scale.y = 0.5;
//    marker.scale.z = 0.5;
//
//    // Set the color -- be sure to set alpha to something non-zero!
//    marker.color.r = 0.0f;
//    marker.color.g = 1.0f;
//    marker.color.b = 0.0f;
//    marker.color.a = 1.0;
//
//    marker.lifetime = ros::Duration();
//
//    // Publish the marker
//    while (marker_pub.getNumSubscribers() < 1)
//    {
//      if (!ros::ok())
//      {
//        return 0;
//      }
//      ROS_WARN_ONCE("Please create a subscriber to the marker");
//      sleep(1);
//    }
//    marker_pub.publish(marker);
//    ROS_INFO("pickup location");
//
//    sleep(5);
//
//    marker.action = visualization_msgs::Marker::DELETE;
//    marker_pub.publish(marker);
//    ROS_INFO("nonvisible");
//
//    sleep(5);
//
//    marker.pose.position.x = -3;
//    marker.action = visualization_msgs::Marker::ADD;
//    marker_pub.publish(marker);
//    ROS_INFO("drop location");
//
//    sleep(5);
//
//    r.sleep();
//  }
}
