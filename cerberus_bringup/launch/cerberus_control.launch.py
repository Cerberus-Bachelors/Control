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
    infer = Node(
        package='cerberus_controller',
        executable='inference',
        name='inference',
        output='both',
    )

    input_handler = Node(
       package='cerberus_controller',
       executable='input_encoder',
    )
    
    nodes = [
        infer,
        input_handler
    ]

    return LaunchDescription(nodes)
