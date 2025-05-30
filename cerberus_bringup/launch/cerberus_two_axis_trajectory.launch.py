# Copyright 2021 Factor Robotics
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    declared_arguments = []

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_joint0",
            default_value="true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_joint1",
            default_value="true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "group_controller",
            default_value="group_position_controller",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "joint_controller",
            default_value="joint_trajectory_controller",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "odrive_1_serial",
            default_value="205B39814D4D",
        )
    )

    enable_joint0 = LaunchConfiguration("enable_joint0")
    enable_joint1 = LaunchConfiguration("enable_joint1")

    group_controller = LaunchConfiguration("group_controller")
    joint_controller = LaunchConfiguration("joint_controller")

    odrive_1_serial = LaunchConfiguration("odrive_1_serial")

    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution(
                [
                    FindPackageShare("cerberus_description"),
                    "urdf",
                    "cerberus_two_axis_odrive.urdf.xacro",
                ]
            ),
            " ",
            "enable_joint0:=",
            enable_joint0,
            " ",
            "enable_joint1:=",
            enable_joint1,
            " ",
            "odrive_1_serial:=",
            odrive_1_serial,
        ]
    )
    robot_description = {"robot_description": robot_description_content}

    robot_controllers = PathJoinSubstitution(
        [
            FindPackageShare("cerberus_bringup"),
            "config",
            "cerberus_twin.yaml",
        ]
    )

    control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        output="both",
        parameters=[robot_description, robot_controllers],
    )

    robot_state_pub_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="both",
        parameters=[robot_description],
    )

    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster", "-c", "/controller_manager"],
    )

    group_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[group_controller, "-c", "/controller_manager"],
        condition=IfCondition(enable_joint0),
    )

    joint_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[joint_controller, "-c", "/controller_manager"],
        condition=IfCondition(enable_joint0),
    )

    nodes = [
        control_node,
        robot_state_pub_node,
        joint_state_broadcaster_spawner,
        group_controller_spawner,
    ]

    return LaunchDescription(declared_arguments + nodes)
