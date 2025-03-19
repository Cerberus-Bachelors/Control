import odrive
from odrive.enums import *
from fibre.libfibre import ObjectLostError
import time
# Connect to ODrive
print("Finding ODrive...")
odrv0 = odrive.find_any()

odrv0.axis0.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE
odrv0.axis1.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE

