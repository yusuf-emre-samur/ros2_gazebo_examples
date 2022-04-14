#ifndef GAZEBO_ROS_PLUGINS_ROS_MODEL_HPP
#define GAZEBO_ROS_PLUGINS_ROS_MODEL_HPP

// Gazebo
#include <gazebo/common/Plugin.hh>
#include <gazebo/gazebo.hh>

// ros
#include <gazebo_ros/node.hpp>
#include <rclcpp/rclcpp.hpp>

// interfaces
#include <std_msgs/msg/string.hpp>

namespace gazebo_ros_plugins {

class RosModelPlugin : public gazebo::ModelPlugin
{
  public:
	// Constructor
	RosModelPlugin();

	~RosModelPlugin();

	void Load(gazebo::physics::ModelPtr _parent, sdf::ElementPtr _sdf);

  private:
	void OnUpdate();
	void topic_callback(const std_msgs::msg::String::SharedPtr msg);

	// gazebo
	gazebo::physics::ModelPtr model_;
	gazebo::event::ConnectionPtr updateConnection_;

	// ros
	gazebo_ros::Node::SharedPtr ros2node_;
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
	rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};
} // namespace gazebo_ros_plugins

#endif
