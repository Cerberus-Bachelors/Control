from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution
from launch_ros.parameter_descriptions import ParameterValue
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
import os

def generate_launch_description():

    # Paths to your URDF and bringup directory
    robot_desc_path = os.path.join(
        get_package_share_directory("cerberus_description"),
        "urdf",
        "cerbiboi.urdf.xacro"
    )
    bringup = get_package_share_directory('cerberus_bringup')

    # Arguments to toggle RViz and the GUI joint state publisher
    rviz_arg = DeclareLaunchArgument(
        'rviz', default_value='true',
        description='Open RViz.'
    )
    gui_arg = DeclareLaunchArgument(
        'gui', default_value='true',
        description='Run the joint_state_publisher_gui.'
    )

    # Robot State Publisher
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        emulate_tty=True,
        output="screen",
        parameters=[{
            'use_sim_time': True,
            'robot_description': ParameterValue(Command(['xacro ', robot_desc_path]),value_type=str)
        }]
    )

    # Joint State Publisher GUI (sliders)
    joint_state_publisher_gui = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui',
        output='screen',
        condition=IfCondition(LaunchConfiguration('gui'))
    )

    # RViz
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', os.path.join(bringup, 'config', 'cerberus.rviz')],
        condition=IfCondition(LaunchConfiguration('rviz')),
        output="screen"
    )

    return LaunchDescription([
        rviz_arg,
        gui_arg,
        robot_state_publisher,
        joint_state_publisher_gui,
        rviz
    ])