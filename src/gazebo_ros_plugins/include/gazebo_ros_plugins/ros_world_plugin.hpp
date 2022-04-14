#ifndef SD_GAZEBO_ROS_PLUGINS_ROS_WORLD_HPP_
#define SD_GAZEBO_ROS_PLUGINS_ROS_WORLD_HPP_

#include <gazebo/common/Plugin.hh>
#include <gazebo/gazebo.hh>
#include <gazebo_ros/node.hpp>
#include <gazebo_ros/utils.hpp>
#include <rclcpp/rclcpp.hpp>

namespace gazebo_ros_plugins {

class RosWorldPlugin : public gazebo::WorldPlugin
{
  public:
	RosWorldPlugin();
	~RosWorldPlugin();

	void Load(gazebo::physics::WorldPtr _world, sdf::ElementPtr _sdf);

  private:
	gazebo_ros::Node::SharedPtr ros2node_;
};
} // namespace gazebo_ros_plugins

#endif
