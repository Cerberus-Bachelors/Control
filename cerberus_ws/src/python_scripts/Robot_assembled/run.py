import odrive
from odrive.enums import *
from fibre.libfibre import ObjectLostError
import time

# Connect to ODrive
print("Finding ODrives...")

odrive_list = []

odrive_list.append(odrive.find_any(serial_number="20763599524B")) ## Front RL HIP
odrive_list.append(odrive.find_any(serial_number="2081356E524B")) ## Front RL THIGH
odrive_list.append(odrive.find_any(serial_number="205B39814D4D")) ## Front RL CALF

odrive_list.append(odrive.find_any(serial_number="208339814D4D"))  ## Rear RL HIP
odrive_list.append(odrive.find_any(serial_number="345735573033"))  ## Rear RL Thigh
odrive_list.append(odrive.find_any(serial_number="346035533033"))  ## Rear RL Calf 

state = 0
bandwidth = 10

if state == 0:
    for odrv in odrive_list:
        odrv.axis0.requested_state = AXIS_STATE_IDLE
        odrv.axis1.requested_state = AXIS_STATE_IDLE

if state == 1:
    for odrv in odrive_list:
        odrv.axis0.requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH
        odrv.axis1.requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH
    time.sleep(2)
    for odrv in odrive_list:
        odrv.axis0.encoder.set_linear_count(0)
        odrv.axis1.encoder.set_linear_count(0)
        odrv.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
        odrv.axis1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

if state == 2:
    odrive_list[1].axis0.controller.input_pos = 12.25/12
    odrive_list[1].axis1.controller.input_pos = -12.25/12





