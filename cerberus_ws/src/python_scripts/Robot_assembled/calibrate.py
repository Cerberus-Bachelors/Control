import odrive
from odrive.enums import *
from fibre.libfibre import ObjectLostError
import time

print("Finding ODrives...")

odrive_list = []

#odrive_list.append(odrive.find_any(serial_number="20763599524B")) ## Front RL HIP
#odrive_list.append(odrive.find_any(serial_number="2081356E524B")) ## Front RL THIGH
odrive_list.append(odrive.find_any(serial_number="205B39814D4D")) ## Front RL CALF

#odrive_list.append(odrive.find_any(serial_number="208339814D4D"))  ## Rear RL HIP
#odrive_list.append(odrive.find_any(serial_number="345735573033"))  ## Rear RL Thigh
#odrive_list.append(odrive.find_any(serial_number="346035533033"))  ## Rear RL Calf 


#for odrv in odrive_list

drive = 0
axis = 1
if drive==0:
    if axis == 0:
        odrive_list[drive].axis0.encoder.config.cpr = 4000
    else:
        odrive_list[drive].axis1.encoder.config.cpr = 2000# Actual value: 2048  

if drive==1:
    if axis == 0:
        odrive_list[drive].axis0.encoder.config.cpr = 4000
    else:
        odrive_list[drive].axis1.encoder.config.cpr = 2000  
    
if drive==2:
    if axis == 0:
        odrive_list[drive].axis0.encoder.config.cpr = 4000
    else:
        odrive_list[drive].axis1.encoder.config.cpr = 2000

if drive==3:
    if axis == 0:
        odrive_list[drive].axis0.encoder.config.cpr = 2000
    else:
        odrive_list[drive].axis1.encoder.config.cpr = 2000

if drive==4:
    if axis == 0:
        odrive_list[drive].axis0.encoder.config.cpr = 2048
    else:
        odrive_list[drive].axis1.encoder.config.cpr = 2000

if drive==5:
    if axis == 0:
        odrive_list[drive].axis0.encoder.config.cpr = 4000
    else:
        odrive_list[drive].axis1.encoder.config.cpr = 2000 

if axis == 0:
    odrive_list[drive].axis0.motor.config.calibration_current = 20
    odrive_list[drive].axis0.config.calibration_lockin.current = 20

    #odrive_list[drive].axis0.encoder.config.pre_calibrated=False
    odrive_list[drive].axis0.motor.config.pre_calibrated=False
    odrive_list[drive].axis0.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE
    #odrive_list[drive].axis0.encoder.config.pre_calibrated=True
    odrive_list[drive].axis0.motor.config.pre_calibrated=True

    #odrive_list[drive].axis0.config.startup_encoder_index_search = True
elif axis == 1:
    odrive_list[drive].axis1.motor.config.calibration_current = 20
    odrive_list[drive].axis1.config.calibration_lockin.current = 20

    #odrive_list[drive].axis1.encoder.config.pre_calibrated=False
    odrive_list[drive].axis1.motor.config.pre_calibrated=False
    odrive_list[drive].axis1.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE
    #odrive_list[drive].axis1.encoder.config.pre_calibrated=True
    odrive_list[drive].axis1.motor.config.pre_calibrated=True

    #odrive_list[drive].axis1.config.startup_encoder_index_search = True
