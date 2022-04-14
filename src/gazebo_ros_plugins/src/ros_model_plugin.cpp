// interface
#include "gazebo_ros_plugins/ros_model_plugin.hpp"
// gazebo
#include <gazebo/common/common.hh>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <ignition/math/Vector3.hh>
// ros
#include <gazebo_ros/utils.hpp>
// other
#include <functional>
#include <memory>
#include <string>

namespace gazebo_ros_plugins {

using namespace std::chrono_literals;

// Constructor
RosModelPlugin::RosModelPlugin()
{
}

RosModelPlugin ::~RosModelPlugin()
{
}

void RosModelPlugin::Load(gazebo::physics::ModelPtr _parent,
						  sdf::ElementPtr _sdf)
{
	// Store the pointer to the model
	this->model_ = _parent;

	// ros node
	ros2node_ = gazebo_ros::Node::Get(_sdf);

	// publisher
	publisher_ =
		ros2node_->create_publisher<std_msgs::msg::String>("test_topic", 10);

	// subscription
	subscription_ = ros2node_->create_subscription<std_msgs::msg::String>(
		"test_topic2", 10,
		std::bind(&RosModelPlugin::topic_callback, this,
				  std::placeholders::_1));

	// Listen to the update event. This event is broadcast every
	// simulation iteration.
	this->updateConnection_ = gazebo::event::Events::ConnectWorldUpdateBegin(
		std::bind(&RosModelPlugin::OnUpdate, this));

	// INFO
	RCLCPP_INFO(ros2node_->get_logger(), "Loaded RosModelPlugin!");
}

// called each iteration of simulation
void RosModelPlugin::OnUpdate()
{
	// create msg
	auto msg = std_msgs::msg::String();
	msg.data = "Hello World ";
	// publish
	publisher_->publish(msg);
}

// called each time receiving message from topic
void RosModelPlugin::topic_callback(const std_msgs::msg::String::SharedPtr msg)
{
	RCLCPP_INFO(ros2node_->get_logger(), msg->data.c_str());
}

// Register this plugin
GZ_REGISTER_MODEL_PLUGIN(RosModelPlugin)

} // namespace gazebo_ros_plugins
