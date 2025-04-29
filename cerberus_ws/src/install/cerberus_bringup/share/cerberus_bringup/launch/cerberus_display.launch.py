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
    bringup = get_package_share_directory('cerberus_bringup')
    description = get_package_share_directory('cerberus_description')

    robot_desc_path = os.path.join(
        description,
        "urdf",
        "cerbiboi.urdf.xacro"
    )

    urdf = xacro.process_file(robot_desc_path).toxml()

    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='both',
        parameters=[
            {'use_sim_time': True},
            {'robot_description': urdf},
        ]
    )

    rviz = Node(
       package='rviz2',
       executable='rviz2',
       arguments=['-d', os.path.join(bringup, 'config', 'cerberus.rviz')],
       condition=IfCondition(LaunchConfiguration('rviz'))
    )
    
    joint_state_publisher = Node(
        package="joint_state_publisher_gui",
        executable="joint_state_publisher_gui",
    )

    nodes = [
        robot_state_publisher,
        DeclareLaunchArgument('rviz', default_value='true',
                              description='Open RViz.'),
        rviz,
        joint_state_publisher
    ]

    return LaunchDescription(nodes)
