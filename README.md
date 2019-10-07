# RobotND-HomeServiceRobot

This project is to simulate a full home service robot capable of navigating to pick up and deliver virtual objects. 
It uses three packages other than the Gazebo (for simulation) and the Rviz (for visualization)

- ROS AMCL (Adaptive Monte Carlo Localization) - This is a probabilistic localization system for a robot moving in 2D. 
  It implements the adaptive Monte Carlo localization approach, which uses a particle filter to track 
  the pose of a robot against a known map.
  
- pickup_objects - This is a package with a node that will communicate with the ROS navigation stack and autonomously
  send two successive goals for your robot to reach. Then, the ROS navigation stack creates a path for your robot 
  while avoiding obstacles on its path.

- add_markers - This is a package with a node to model a virtual object with markers in rviz. The virtual object first appears in its pickup zone, disappears to represent being picked up when your robot arrives at the first goal and then re-appears at the drop zone to represent being delivered when your robot arrives at the second goal.

<img src="https://raw.githubusercontent.com/sungpily/RobotND-HomeServiceRobot/master/screenshot/Screenshot%20from%202019-10-05%2012-20-09.png" width="500">
