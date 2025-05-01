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

print("Erasing configuration")
try:
    for odrv in odrive_list:
        odrv.erase_configuration()
except ObjectLostError:
    pass

time.sleep(5)

odrive_list.clear()

odrive_list.append(odrive.find_any(serial_number="20763599524B")) ## Front RL HIP
odrive_list.append(odrive.find_any(serial_number="2081356E524B")) ## Front RL THIGH
odrive_list.append(odrive.find_any(serial_number="205B39814D4D")) ## Front RL CALF

odrive_list.append(odrive.find_any(serial_number="208339814D4D"))  ## Rear RL HIP
odrive_list.append(odrive.find_any(serial_number="345735573033"))  ## Rear RL Thigh
odrive_list.append(odrive.find_any(serial_number="346035533033"))  ## Rear RL Calf 

print("Confing configuration")

drive = 2

for count, odrv in enumerate(odrive_list):
    if count != drive:
        continue
    odrv.config.dc_max_positive_current = 40.0
    odrv.config.dc_max_negative_current = -10

    odrv.axis0.motor.config.current_lim = 25
    odrv.axis0.controller.config.vel_limit = 25
    odrv.axis0.motor.config.pole_pairs = 11
    odrv.axis0.motor.config.torque_constant = 8.27/340

    odrv.axis1.motor.config.current_lim = 25
    odrv.axis1.controller.config.vel_limit = 25
    odrv.axis1.motor.config.pole_pairs = 11
    odrv.axis1.motor.config.torque_constant = 8.27/340

    if count==0:
        odrv.axis0.encoder.config.cpr = 4000
        odrv.axis1.encoder.config.cpr = 2048

    if count==1:
        odrv.axis0.encoder.config.cpr = 4000
        odrv.axis1.encoder.config.cpr = 2000  

    if count==2:
        odrv.axis0.encoder.config.cpr = 4000
        odrv.axis1.encoder.config.cpr = 2000 

    if count==3:
        odrv.axis0.encoder.config.cpr = 2000
        odrv.axis1.encoder.config.cpr = 2000  

    if count==4:
        odrv.axis0.encoder.config.cpr = 2048
        odrv.axis1.encoder.config.cpr = 2000

    if count==5:
        odrv.axis0.encoder.config.cpr = 4000
        odrv.axis1.encoder.config.cpr = 2000

    print("Calibration")
    
    # Calibrate
    odrv.axis0.motor.config.calibration_current = 20
    odrv.axis0.config.calibration_lockin.current = 20

    odrv.axis0.motor.config.pre_calibrated = False
    odrv.axis0.encoder.config.pre_calibrated = False
    odrv.axis0.encoder.config.use_index = True

    odrv.axis0.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE
    
    odrv.axis1.motor.config.calibration_current = 20
    odrv.axis1.config.calibration_lockin.current = 20

    odrv.axis1.motor.config.pre_calibrated = False
    odrv.axis1.encoder.config.pre_calibrated = False
    odrv.axis1.encoder.config.use_index = True

    odrv.axis1.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE
    
    time.sleep(20)
    
    odrv.axis0.motor.config.pre_calibrated = True
    odrv.axis0.encoder.config.pre_calibrated = True

    odrv.axis0.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
    odrv.axis0.controller.config.input_mode = INPUT_MODE_POS_FILTER
    odrv.axis0.controller.config.input_filter_bandwidth = 10

    odrv.axis1.motor.config.pre_calibrated = True
    odrv.axis1.encoder.config.pre_calibrated = True

    odrv.axis1.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
    odrv.axis1.controller.config.input_mode = INPUT_MODE_POS_FILTER
    odrv.axis1.controller.config.input_filter_bandwidth = 10

    try:
        print("Saving configuration")
        odrv.save_configuration()
    except ObjectLostError:
        pass
