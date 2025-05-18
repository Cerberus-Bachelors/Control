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
            "joint_controller",
            default_value="joint_trajectory_controller",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "pos_controller",
            default_value="group_position_controller",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "effort_controller",
            default_value="group_effort_controller",
        )
    )

    bringup = get_package_share_directory('cerberus_bringup')
    gazebo = get_package_share_directory('cerberus_gazebo')
    description = get_package_share_directory('cerberus_description')
    gz_sim = get_package_share_directory('ros_gz_sim')

    robot_desc_path = os.path.join(
        description,
        "urdf",
        "cerbiboi.urdf.xacro"
    )

    joint_controller = LaunchConfiguration("joint_controller")
    pos_controller = LaunchConfiguration("pos_controller")
    effort_controller = LaunchConfiguration("effort_controller")


    urdf = xacro.process_file(robot_desc_path).toxml()

    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(gz_sim, 'launch', 'gz_sim.launch.py')),
        launch_arguments={'gz_args': PathJoinSubstitution([
            '-r',
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
            '-z', '0.35'
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

    joint_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[joint_controller, "-c", "/controller_manager"],
    )
    
    pos_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[pos_controller, "-c", "/controller_manager"],
    )

    effort_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[effort_controller, "-c", "/controller_manager"],
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

    nodes = [
        gz_sim,
        spawn_robot,
        DeclareLaunchArgument('rviz', default_value='true',
                              description='Open RViz.'),
        bridge,
        robot_state_publisher,
        rviz,
        pos_controller_spawner,
        joint_state_broadcaster_spawner,
        #input_handler,
        #infer,
    ]

    return LaunchDescription(declared_arguments + nodes)
