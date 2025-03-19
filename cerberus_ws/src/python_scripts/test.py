import odrive
from odrive.enums import *
import time

# Connect to ODrive
print("Finding ODrive...")
odrv0 = odrive.find_any()
print("Found ODrive!")

# Set new zero
odrv0.axis0.requested_state = AXIS_STATE_IDLE
odrv0.axis0.encoder.set_linear_count(0)

odrv0.axis1.requested_state = AXIS_STATE_IDLE
odrv0.axis1.encoder.set_linear_count(0)
print("Set new zero!")


# Ensure correct control methods
odrv0.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
odrv0.axis0.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
odrv0.axis0.controller.config.input_mode = INPUT_MODE_POS_FILTER

odrv0.axis1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
odrv0.axis1.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
odrv0.axis1.controller.config.input_mode = INPUT_MODE_POS_FILTER


# Controller Values
odrv0.axis0.controller.config.vel_limit = 20.0
odrv0.axis0.trap_traj.config.accel_limit = 15.0
odrv0.axis0.trap_traj.config.decel_limit = 15.0
odrv0.axis0.controller.config.inertia = 0.0

odrv0.axis1.controller.config.vel_limit = 20.0
odrv0.axis1.trap_traj.config.accel_limit = 15.0
odrv0.axis1.trap_traj.config.decel_limit = 15.0
odrv0.axis1.controller.config.inertia = 0.0


# Bandwidth control
initial_bandwidth = 5
bandwidth_step = 1  # Increase amount
max_bandwidth = 20  # Set a limit
odrv0.axis0.controller.config.input_filter_bandwidth = initial_bandwidth
odrv0.axis1.controller.config.input_filter_bandwidth = initial_bandwidth
# Filter control
#odrv0.axis1.controller.config.pos_gain = 20
#odrv0.axis1.controller.config.vel_gain = 0.1
#odrv0.axis1.controller.config.vel_integrator_gain = 0.05

def wait_for_motors(axes, threshold=0.2, vel_threshold=0.2, timeout=10):
    """
    Waits for all motors in 'axes' to reach their target positions.
    
    :param axes: list of ODrive axes (e.g., [odrv0.axis0, odrv0.axis1])
    :param threshold: Allowed position error (default: 0.1 turns)
    :param vel_threshold: Allowed velocity to consider the motor settled (default: 0.1 turns/sec)
    :param timeout: Maximum wait time in seconds
    """
    start_time = time.time()
    
    while time.time() - start_time < timeout:
        all_settled = True  # Assume all are settled unless we find otherwise
        
        for axis in axes:
            pos_error = abs(axis.controller.input_pos - axis.encoder.pos_estimate)
            velocity = abs(axis.encoder.vel_estimate)
            
            # Check if this axis is outside the acceptable thresholds
            if pos_error >= threshold or velocity >= vel_threshold:
                all_settled = False
                break  # No need to check further axes right now
        
        if all_settled:
            return  # All motors have reached their setpoints
        
        time.sleep(0.05)  # Check every 50ms
    
    print("Warning: Timeout reached, not all motors may have settled!")
test = False
try:
    print("Lets go to work!")
    if test:
        odrv0.axis0.controller.config.input_filter_bandwidth = 15
        odrv0.axis1.controller.config.input_filter_bandwidth = 15

        odrv0.axis0.controller.input_pos = 12.25/2
        odrv0.axis1.controller.input_pos = 12.25/2
        time.sleep(1)
        odrv0.axis0.controller.input_pos = 12.25/3
        odrv0.axis1.controller.input_pos = 12.25/3
        time.sleep(0.5)
        odrv0.axis0.controller.input_pos = 12.25/4
        odrv0.axis1.controller.input_pos = 12.25/4
        time.sleep(0.5)
        odrv0.axis0.controller.input_pos = 12.25/2
        odrv0.axis1.controller.input_pos = 12.25/2
        time.sleep(0.5)
        odrv0.axis0.controller.input_pos = -12.25/4
        odrv0.axis1.controller.input_pos = -12.25/4
        time.sleep(0.5)
        odrv0.axis0.controller.input_pos = 0
        odrv0.axis1.controller.input_pos = 0
        wait_for_motors([odrv0.axis0, odrv0.axis1])
        odrv0.axis0.requested_state = AXIS_STATE_IDLE
        odrv0.axis1.requested_state = AXIS_STATE_IDLE

    else:
        for i in range(50):
            odrv0.axis0.controller.input_pos = -12.25 / 4
            odrv0.axis1.controller.input_pos = 12.25 / 4

            wait_for_motors([odrv0.axis0, odrv0.axis1])

            odrv0.axis0.controller.input_pos = 12.25 / 4
            odrv0.axis1.controller.input_pos = -12.25 / 4
            wait_for_motors([odrv0.axis0, odrv0.axis1])


            # Increase bandwidth every 2 repetitions
            if (i + 1) % 2 == 0:
                new_bandwidth = min(odrv0.axis1.controller.config.input_filter_bandwidth + bandwidth_step, max_bandwidth)
                odrv0.axis0.controller.config.input_filter_bandwidth = new_bandwidth
                odrv0.axis1.controller.config.input_filter_bandwidth = new_bandwidth
                print(f"Iteration {i+1}: Increased bandwidth to {new_bandwidth}")

        print("Finished working!")
        odrv0.axis0.controller.config.input_filter_bandwidth = 5
        odrv0.axis0.controller.input_pos = 0
        odrv0.axis1.controller.config.input_filter_bandwidth = 5
        odrv0.axis1.controller.input_pos = 0
        wait_for_motors([odrv0.axis0, odrv0.axis1])  # Ensure it returns to zero before idling
        odrv0.axis0.requested_state = AXIS_STATE_IDLE
        odrv0.axis1.requested_state = AXIS_STATE_IDLE

except KeyboardInterrupt:
    print("Exiting, going to zero")
    odrv0.axis0.controller.config.input_filter_bandwidth = 5
    odrv0.axis0.controller.input_pos = 0
    odrv0.axis1.controller.config.input_filter_bandwidth = 5
    odrv0.axis1.controller.input_pos = 0
    wait_for_motors([odrv0.axis0, odrv0.axis1])  # Ensure it reaches zero
    odrv0.axis0.requested_state = AXIS_STATE_IDLE
    odrv0.axis1.requested_state = AXIS_STATE_IDLE