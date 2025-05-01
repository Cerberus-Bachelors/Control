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

for count, odrv in enumerate(odrive_list):
    odrv.config.dc_max_positive_current = 40.0
    odrv.config.dc_max_negative_current = -10


    odrv.axis0.motor.config.current_lim = 35
    odrv.axis0.controller.config.vel_limit = 25
    odrv.axis0.motor.config.pole_pairs = 11
    odrv.axis0.motor.config.torque_constant = 8.27/340

    odrv.axis0.encoder.config.cpr = 4000

    odrv.axis1.motor.config.current_lim = 35
    odrv.axis1.controller.config.vel_limit = 25
    odrv.axis1.motor.config.pole_pairs = 11
    odrv.axis1.motor.config.torque_constant = 8.27/340

    odrv.axis1.encoder.config.cpr = 2000

print("Saving configuration")
try:
    for odrv in odrive_list:
        odrv.save_configuration()
except ObjectLostError:
    pass