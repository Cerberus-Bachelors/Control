#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint

class RepeatingTrajectoryNode(Node):
    def __init__(self):
        super().__init__('repeating_trajectory_node')
        
        # Create a publisher for the JointTrajectory message
        self.trajectory_publisher = self.create_publisher(JointTrajectory,
                                                          '/joint_trajectory_controller/joint_trajectory',
                                                          10)

        # Create a timer to call self.publish_trajectory every 15 seconds
        self.timer_period = 12.0  # seconds
        self.timer = self.create_timer(self.timer_period, self.publish_trajectory)

        # Pre-define the trajectory message
        self.trajectory_msg = JointTrajectory()
        self.trajectory_msg.joint_names = ["joint0", "joint1", "joint2"]

        # Create the points
        point1 = JointTrajectoryPoint()
        point1.positions = [0.0, 0.0, -0.8]
        point1.velocities = [0.0, 0.0, 0.0]
        point1.time_from_start.sec = 3

        point2 = JointTrajectoryPoint()
        point2.positions = [19.242255, 7.0, -0.8]
        point2.velocities = [0.0, 0.0, 0.0]
        point2.time_from_start.sec = 6

        point3 = JointTrajectoryPoint()
        point3.positions = [23.242255, -7.0, -8.0]
        point3.velocities = [0.0, 0.0, 0.0]
        point3.time_from_start.sec = 9

        point4 = JointTrajectoryPoint()
        point4.positions = [33.242255, 8.0, -8.0]
        point4.velocities = [0.0, 0.0, 0.0]
        point4.time_from_start.sec = 12

        self.trajectory_msg.points = [point1, point2, point3, point4]

        # Publish once on startup
        self.publish_trajectory()

    def publish_trajectory(self):
        """
        Publish the trajectory message. The header stamp is set to the current time
        so the controller knows it is a new message each time.
        """
        # Set the header time to "now"
        self.trajectory_msg.header.stamp = self.get_clock().now().to_msg()

        self.get_logger().info("Publishing repeating trajectory...")
        self.trajectory_publisher.publish(self.trajectory_msg)


def main(args=None):
    rclpy.init(args=args)
    node = RepeatingTrajectoryNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
