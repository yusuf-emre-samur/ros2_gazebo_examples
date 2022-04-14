#include <gazebo_ros_plugins/ros_world_plugin.hpp>

namespace gazebo_ros_plugins {

RosWorldPlugin::RosWorldPlugin() : gazebo::WorldPlugin()
{
}

RosWorldPlugin::~RosWorldPlugin()
{
	ros2node_.reset();
}

void RosWorldPlugin::Load(gazebo::physics::WorldPtr _world,
						  sdf::ElementPtr _sdf)
{
	ros2node_ = gazebo_ros::Node::Get(_sdf);
	RCLCPP_INFO(ros2node_->get_logger(), "Loaded RosWorldPlugin!");
}

GZ_REGISTER_WORLD_PLUGIN(RosWorldPlugin)

} // namespace gazebo_ros_plugins
