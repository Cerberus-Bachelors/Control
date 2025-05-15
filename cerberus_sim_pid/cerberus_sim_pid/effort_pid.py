import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray

class PIDEffortController(Node):
    def __init__(self):
        super().__init__('pid_effort_controller')
        self.sub_joint_state = self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)
        self.pub_effort_cmd = self.create_publisher(Float64MultiArray, '/group_effort_controller/commands', 10)
        self.sub_target_state = self.create_subscription(Float64MultiArray, '/group_position_controller/commands', self.target_callback, 10)
        self.desired_positions = {}
        self.current_positions = {}
        self.previous_errors = {}
        self.integral_errors = {}

        self.name_order = ["FL_hip_joint","FR_hip_joint","RL_hip_joint","RR_hip_joint","FL_thigh_joint","FR_thigh_joint","RL_thigh_joint","RR_thigh_joint","FL_calf_joint","FR_calf_joint","RL_calf_joint","RR_calf_joint"]

        p = 50.0
        i = 0.9
        d = 0.05

        self.gains = {
            'FL_hip_joint': {'p': p, 'i': i, 'd': d},
            'FR_hip_joint': {'p': p, 'i': i, 'd': d},
            'RL_hip_joint': {'p': p, 'i': i, 'd': d},
            'RR_hip_joint': {'p': p, 'i': i, 'd': d},
    
            'FL_thigh_joint': {'p': p, 'i': i, 'd': d},
            'FR_thigh_joint': {'p': p, 'i': i, 'd': d},
            'RL_thigh_joint': {'p': p, 'i': i, 'd': d},
            'RR_thigh_joint': {'p': p, 'i': i, 'd': d},
    
            'FL_calf_joint': {'p': p, 'i': i, 'd': d},
            'FR_calf_joint': {'p': p, 'i': i, 'd': d},
            'RL_calf_joint': {'p': p, 'i': i, 'd': d},
            'RR_calf_joint': {'p': p, 'i': i, 'd': d},
        }

        self.timer = self.create_timer(0.005, self.control_loop)  # 100 Hz

    def joint_state_callback(self, msg: JointState):
        for name, pos in zip(msg.name, msg.position):
            self.current_positions[name] = pos
    
    def target_callback(self, msg: Float64MultiArray):
        for name, target in zip(self.name_order, msg.data):
            self.desired_positions[name] = target*0.25

    def control_loop(self):
        cmd_msg = Float64MultiArray()
        efforts = []

        if len(self.current_positions)==0 or len(self.desired_positions)==0:
            return;
        for joint in self.name_order:
            error = self.desired_positions[joint] - self.current_positions.get(joint, 0.0)
            self.integral_errors[joint] = self.integral_errors.get(joint, 0.0) + error * 0.005
            derivative = (error - self.previous_errors.get(joint, 0.0)) / 0.005

            effort = (self.gains[joint]['p'] * error +
                      self.gains[joint]['i'] * self.integral_errors[joint] +
                      self.gains[joint]['d'] * derivative)

            efforts.append(effort)
            self.previous_errors[joint] = error

        cmd_msg.data = efforts
        self.pub_effort_cmd.publish(cmd_msg)

def main(args=None):
    rclpy.init(args=args)
    node = PIDEffortController()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
