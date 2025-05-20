# Control system for the Cerberus quadruped
This repository contains launch files for running simulators and controllers.

# Inference
To run inference
First change the path to the model in the inference.cpp file.<br/> 
Then build and source the cerberus_controller package.

It can then be run using the ```Ros2 run cerberus_controller inference```

Do note that the cerberus controller needs the [cerberus_msgs](https://github.com/Cerberus-Bachelors/cerberus_msgs/tree/main) package<br/>  as well as an observation tensor message from [cerberus_msgs](https://github.com/Cerberus-Bachelors/cerberus_msgs/tree/main) either delivered<br/> from the input_encoder node in the cerberus_controller package or a custom one at a rate of 50Hz.

## Odrive hardware
The hardware interface is sourced from the [ros2 control odrive repository by Factor-Robotics](https://github.com/Factor-Robotics/odrive_ros2_control)