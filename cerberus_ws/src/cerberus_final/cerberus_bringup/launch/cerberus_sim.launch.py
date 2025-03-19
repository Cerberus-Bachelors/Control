import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument

from launch.actions import IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.parameter_descriptions import ParameterValue
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution
from launch_ros.parameter_descriptions import ParameterValue
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
import os
import xacro

from launch_ros.actions import Node


def generate_launch_description():

    bringup = get_package_share_directory('cerberus_bringup')
    gazebo = get_package_share_directory('cerberus_gazebo')
    description = get_package_share_directory('cerberus_description')
    gz_sim = get_package_share_directory('ros_gz_sim')

    group_controller = LaunchConfiguration("group_controller")

    robot_desc_path = os.path.join(
        description,
        "urdf",
        "cerbiboi.urdf.xacro"
    )

    urdf = xacro.process_file(robot_desc_path).toxml()

    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(gz_sim, 'launch', 'gz_sim.launch.py')),
        launch_arguments={'gz_args': PathJoinSubstitution([
            gazebo,
            'worlds',
            'cerberus.sdf'
        ])}.items(),
    )

    spawn_robot = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=[
            '-name', 'cerberus',
            '-string', urdf,
            '-z', '1'
        ],
        output='screen'
    )

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

    bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        parameters=[{
            'config_file': os.path.join(bringup, 'config', 'cerberus_msg.yaml'),
            'qos_overrides./tf_static.publisher.durability': 'transient_local',
        }],
        output='screen'
    )
    
    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster", "-c", "/controller_manager"],
    )
    
    #group_controller_spawner = Node(
    #    package="controller_manager",
    #    executable="spawner",
    #    arguments=["group_position_controller", "-c", "/controller_manager"],
    #)
    group_effort_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["group_effort_controller", "-c", "/controller_manager"],
    )

    return LaunchDescription([
        gz_sim,
        spawn_robot,
        DeclareLaunchArgument('rviz', default_value='true',
                              description='Open RViz.'),
        bridge,
        robot_state_publisher,
        rviz,
        group_effort_spawner,
        joint_state_broadcaster_spawner,
    ])
