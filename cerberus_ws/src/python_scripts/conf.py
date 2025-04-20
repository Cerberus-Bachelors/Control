import odrive
from odrive.enums import *
from fibre.libfibre import ObjectLostError
import time

# Connect to ODrive
print("Finding ODrive...")
odrv0 = odrive.find_any()

print("Erasing configuration")
try:
    odrv0.erase_configuration()
except ObjectLostError:
    pass

time.sleep(5)

print("Finding ODrive...")
odrv0 = odrive.find_any()

odrv0.config.dc_max_positive_current = 40.0
odrv0.config.dc_max_negative_current = -10


odrv0.axis0.motor.config.current_lim = 35
odrv0.axis0.controller.config.vel_limit = 25
odrv0.axis0.motor.config.pole_pairs = 11
odrv0.axis0.motor.config.torque_constant = 8.27/340

odrv0.axis0.encoder.config.cpr = 2000

#odrv0.axis0.encoder.config.use_index = True
odrv0.axis0.encoder.config.pre_calibrated=False
odrv0.axis0.motor.config.pre_calibrated=False
odrv0.axis0.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE
odrv0.axis0.encoder.config.pre_calibrated=True
odrv0.axis0.motor.config.pre_calibrated=True

odrv0.axis0.config.startup_encoder_index_search = True

odrv0.axis0.config.watchdog_timeout = 0


odrv0.axis1.motor.config.current_lim = 25
odrv0.axis1.controller.config.vel_limit = 25
odrv0.axis1.motor.config.pole_pairs = 11
odrv0.axis1.motor.config.torque_constant = 8.27/340

odrv0.axis1.encoder.config.cpr = 2000

#odrv0.axi10.encoder.config.use_index = True
odrv0.axis1.encoder.config.pre_calibrated=False
odrv0.axis1.motor.config.pre_calibrated=False
odrv0.axis1.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE
odrv0.axis1.encoder.config.pre_calibrated=True
odrv0.axis1.motor.config.pre_calibrated=True

odrv0.axis1.config.startup_encoder_index_search = True

odrv0.axis1.config.watchdog_timeout = 0

print("Saving configuration")
try:
    odrv0.save_configuration()
except ObjectLostError:
    pass