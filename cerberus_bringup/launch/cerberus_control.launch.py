import os

from ament_index_python.packages import get_package_share_directory
import xacro

from launch import LaunchDescription

from launch.actions import IncludeLaunchDescription
from launch.actions import DeclareLaunchArgument

from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

from launch.conditions import IfCondition

from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution




def generate_launch_description():

    declared_arguments = []

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_FL_hip_joint",
            default_value="true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_FR_hip_joint",
            default_value="true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_RL_hip_joint",
            default_value="true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_RR_hip_joint",
            default_value="true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_FL_thigh_joint",
            default_value="true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_FR_thigh_joint",
            default_value="true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_RL_thigh_joint",
            default_value="true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_RR_thigh_joint",
            default_value="true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_FL_calf_joint",
            default_value="true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_FR_calf_joint",
            default_value="true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_RL_calf_joint",
            default_value="true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_RR_calf_joint",
            default_value="true",
        )
    )

    declared_arguments.append(
    DeclareLaunchArgument(
        "front_hip_serial",
        default_value="20763599524B",
    )
)

    declared_arguments.append(
        DeclareLaunchArgument(
            "front_thigh_serial",
            default_value="2081356E524B",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "front_calf_serial",
            default_value="205B39814D4D",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "rear_hip_serial",
            default_value="208339814D4D",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "rear_thigh_serial",
            default_value="345735573033",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "rear_calf_serial",
            default_value="346035533033",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "group_controller",
            default_value="group_position_controller",
        )
    )

    enable_FL_hip_joint = LaunchConfiguration("enable_FL_hip_joint")
    enable_FR_hip_joint = LaunchConfiguration("enable_FR_hip_joint")
    enable_RL_hip_joint = LaunchConfiguration("enable_RL_hip_joint")
    enable_RR_hip_joint = LaunchConfiguration("enable_RR_hip_joint")

    enable_FL_thigh_joint = LaunchConfiguration("enable_FL_thigh_joint")
    enable_FR_thigh_joint = LaunchConfiguration("enable_FR_thigh_joint")
    enable_RL_thigh_joint = LaunchConfiguration("enable_RL_thigh_joint")
    enable_RR_thigh_joint = LaunchConfiguration("enable_RR_thigh_joint")

    enable_FL_calf_joint = LaunchConfiguration("enable_FL_calf_joint")
    enable_FR_calf_joint = LaunchConfiguration("enable_FR_calf_joint")
    enable_RL_calf_joint = LaunchConfiguration("enable_RL_calf_joint")
    enable_RR_calf_joint = LaunchConfiguration("enable_RR_calf_joint")

    front_hip_serial = LaunchConfiguration("front_hip_serial")
    front_thigh_serial = LaunchConfiguration("front_thigh_serial")
    front_calf_serial = LaunchConfiguration("front_calf_serial")
    rear_hip_serial = LaunchConfiguration("rear_hip_serial")
    rear_thigh_serial = LaunchConfiguration("rear_thigh_serial")
    rear_calf_serial = LaunchConfiguration("rear_calf_serial")

    group_controller = LaunchConfiguration("group_controller")

    group_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[group_controller, "-c", "/controller_manager"],
    )

    infer = Node(
        package='cerberus_controller',
        executable='inference',
        name='inference',
        output='both',
    )

    input_handler = Node(
       package='cerberus_controller',
       executable='input_encoder',
       name='input_encoder',
       output='both',
    )

    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution(
                [
                    FindPackageShare("cerberus_description"),
                    "urdf",
                    "cerberus_odrive.urdf.xacro",
                ]
            ),
            " ",
            "enable_FL_hip_joint:=",
            enable_FL_hip_joint,
            " ",
            "enable_FR_hip_joint:=",
            enable_FR_hip_joint,
            " ",
            "enable_RL_hip_joint:=",
            enable_RL_hip_joint,
            " ",
            "enable_RR_hip_joint:=",
            enable_RR_hip_joint,
            " ",
            "enable_FL_thigh_joint:=",
            enable_FL_thigh_joint,
            " ",
            "enable_FR_thigh_joint:=",
            enable_FR_thigh_joint,
            " ",
            "enable_RL_thigh_joint:=",
            enable_RL_thigh_joint,
            " ",
            "enable_RR_thigh_joint:=",
            enable_RR_thigh_joint,
            " ",
            "enable_FL_calf_joint:=",
            enable_FL_calf_joint,
            " ",
            "enable_FR_calf_joint:=",
            enable_FR_calf_joint,
            " ",
            "enable_RL_calf_joint:=",
            enable_RL_calf_joint,
            " ",
            "enable_RR_calf_joint:=",
            enable_RR_calf_joint,
            " ",
            "front_hip_serial:=",
            front_hip_serial,
            " ",
            "front_thigh_serial:=",
            front_thigh_serial,
            " ",
            "front_calf_serial:=",
            front_calf_serial,
            " ",
            "rear_hip_serial:=",
            rear_hip_serial,
            " ",
            "rear_thigh_serial:=",
            rear_thigh_serial,
            " ",
            "rear_calf_serial:=",
            rear_calf_serial,
        ]
    )

    robot_description = {"robot_description": robot_description_content}

    robot_controllers = PathJoinSubstitution(
        [
            FindPackageShare("cerberus_bringup"),
            "config",
            "cerberus.yaml",
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
    
    nodes = [
        control_node,
        robot_state_pub_node,
        joint_state_broadcaster_spawner,
        group_controller_spawner,
        infer,
        input_handler
    ]

    return LaunchDescription(declared_arguments + nodes)
