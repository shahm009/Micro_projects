# AuTax - Autonomous Taxi Service

## Overview

AuTax is an innovative autonomous taxi service designed to provide safe, efficient, and reliable rides in urban environments. Built on the Robot Operating System 2 (ROS2) Humble, AuTax integrates various sensors and tools to navigate and operate autonomously.

## Features

- **Advanced Obstacle Avoidance:** Utilizes a sonar sensor array for real-time navigation and obstacle detection.
- **Comprehensive Visualization:** Sensor data is visualized in RViz, offering a clear view of the vehicle's surroundings.
- **Smart Recognition:** Powered by a Raspberry Pi 4, AuTax recognizes people, vehicles, and other objects in its environment.
- **User-Friendly Dashboard:** Passengers can easily select locations and start navigation through an intuitive interface, which includes a live camera feed.
- **High-Definition Navigation:** Equipped with GPS and a compass for accurate positioning and navigation.
- **Integration with Nav2:** Leverages the Navigation2 (Nav2) framework for robust path planning and navigation capabilities.
- **Custom Design:** Features 3D printed components for LiDAR, ensuring durability and seamless functionality.

## Installation

To set up AuTax, follow these steps:

### Prerequisites

- **Hardware Requirements:**
  - Raspberry Pi 4
  - Sonar Sensor Array
  - GPS Module
  - Compass

- **Software Requirements:**
  - ROS2 Humble
  - Nav2 (Navigation2 stack)
  - RViz

### Steps to Install

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/shahm009/Micro_projects.git
   cd Micro_projects/AuTax
   ```

2. **Install ROS2 Humble and Nav2:**
   Follow the instructions on the official [ROS2 Humble Installation Guide](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html) to set up ROS2. For Nav2, refer to the [Nav2 Installation Guide](https://navigation.ros.org/getting-started/index.html).

3. **Build the ROS2 Packages:**
   Navigate to your ROS2 workspace and build the packages:
   ```bash
   colcon build
   ```

4. **Source the Workspace:**
   ```bash
   source install/setup.bash
   ```

## Usage

### Running the AuTax System

1. **Launch the AuTax System:**
   Use the following command to launch the AuTax nodes:
   ```bash
   ros2 launch autax_launch.py
   ```

2. **Visualize in RViz:**
   To visualize the sensor data and navigation path, run:
   ```bash
   ros2 run rviz2 rviz2
   ```

3. **Access the Dashboard:**
   Open your web browser and navigate to `http://localhost:8080` to access the AuTax dashboard and start navigation.

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature/YourFeature
   ```
3. Make your changes and commit them:
   ```bash
   git commit -m "Add your message"
   ```
4. Push to the branch:
   ```bash
   git push origin feature/YourFeature
   ```
5. Open a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

Special thanks to @linuxpapa for their support and contributions to this project.

## Contact

For inquiries or support, please reach out via email: [thunderxx108@gmail.com](mailto:thunderxx108@gmail.com)
