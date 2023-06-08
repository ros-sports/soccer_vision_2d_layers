# Soccer Vision 2D Layers for RQt Image Overlay

[![Build and Test (humble)](../../actions/workflows/build_and_test_humble.yaml/badge.svg?branch=rolling)](../../actions/workflows/build_and_test_humble.yaml?query=branch:rolling)
[![Build and Test (iron)](../../actions/workflows/build_and_test_iron.yaml/badge.svg?branch=rolling)](../../actions/workflows/build_and_test_iron.yaml?query=branch:rolling)
[![Build and Test (rolling)](../../actions/workflows/build_and_test_rolling.yaml/badge.svg?branch=rolling)](../../actions/workflows/build_and_test_rolling.yaml?query=branch:rolling)

A collection of [RQt Image Overlay](https://rqt-image-overlay.readthedocs.io/en/latest/index.html#) layers for drawing [Soccer Vision 2D Msgs](https://github.com/ros-sports/soccer_interfaces/tree/rolling/soccer_vision_2d_msgs) onto an image.

![](images/screenshot.png)

## Installation

[Install RQt Image Overlay](https://rqt-image-overlay.readthedocs.io/en/latest/installation.html#installation) if you haven't installed it yet.

In your ROS2 workspace, clone the repository and its dependencies using:

```
git clone https://github.com/ros-sports/soccer_vision_2d_layers.git src/soccer_vision_2d_layers
vcs import src < src/soccer_vision_2d_layers/dependencies.repos
```

Build the package and its dependencies by running in the workspace root directory:

```
colcon build
```
