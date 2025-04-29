import odrive
from odrive.enums import *
from fibre.libfibre import ObjectLostError
import time

# Connect to ODrive
print("Finding ODrives...")

odrive_list = []

odrive_list.append(odrive.find_any(serial_number="20763599524B"))
odrive_list.append(odrive.find_any(serial_number="2081356E524B"))
odrive_list.append(odrive.find_any(serial_number="205B39814D4D"))


state = 0
bandwidth = 10

if state == 0:
    for odrv in odrive_list:
        odrv.axis0.requested_state = AXIS_STATE_IDLE
        odrv.axis1.requested_state = AXIS_STATE_IDLE

if state == 1:
    for odrv in odrive_list:
        odrv.axis0.encoder.set_linear_count(0)
        odrv.axis1.encoder.set_linear_count(0)
        odrv.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
        odrv.axis0.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
        odrv.axis0.controller.config.input_mode = INPUT_MODE_POS_FILTER
        odrv.axis1.controller.config.input_filter_bandwidth = bandwidth

        odrv.axis1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
        odrv.axis1.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
        odrv.axis1.controller.config.input_mode = INPUT_MODE_POS_FILTER
        odrv.axis1.controller.config.input_filter_bandwidth = bandwidth
if state == 2:
    odrive_list[1].axis0.controller.input_pos = 12.25/12
    odrive_list[1].axis1.controller.input_pos = -12.25/12

    odrive_list[2].axis0.controller.input_pos = -12.25/10
    odrive_list[2].axis1.controller.input_pos = 12.25/10





