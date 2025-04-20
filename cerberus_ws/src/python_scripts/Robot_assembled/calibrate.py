import odrive
from odrive.enums import *
from fibre.libfibre import ObjectLostError
import time

print("Finding ODrives...")

odrive_list = []

odrive_list.append(odrive.find_any(serial_number="20763599524B"))
odrive_list.append(odrive.find_any(serial_number="2081356E524B"))
odrive_list.append(odrive.find_any(serial_number="205B39814D4D"))

#odrive_list.append(odrive.find_any(serial_number="208339814D4D"))
#odrive_list.append(odrive.find_any(serial_number="346935563033"))
#odrive_list.append(odrive.find_any(serial_number="346035533033"))



#for odrv in odrive_list

drive = 0
axis = 1
if drive==0 or drive==1 or drive==2:
    if axis == 0:
        odrive_list[drive].axis0.encoder.config.cpr = 4000
    else:
        if odrive == 0:
            odrive_list[drive].axis1.encoder.config.cpr = 2048  
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
