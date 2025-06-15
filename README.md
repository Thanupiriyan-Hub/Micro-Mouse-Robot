# Maze-Solving Micro Mouse Project

## Overview
This repository contains the code and documentation for the **Maze-Solving Micro Mouse Robot** project developed for a robotics competition in 2024. The robot uses a flood-fill algorithm to navigate a maze autonomously and determine the shortest path to the goal.

> ⚠️ **Important Note**:  
> The flood-fill algorithm logic used in this competition is **not included** in this repository.  
> Only the sensor-related libraries and necessary interface functions are shared here.  
> If you're interested in the full algorithm or implementation details, feel free to contact me via [LinkedIn](https://linkedin.com/in/your-profile) or email.

## Competition Format
The competition was based on the classic **Micro Mouse challenge**, where the task is to navigate a **16×16 cell maze**, with each cell measuring **16cm × 16cm**. The objective is for the robot to autonomously find and travel the **shortest path to the center** of the maze in the least possible time.

Each team had to develop their own algorithms, hardware integration, and path-planning logic to efficiently guide their robot from the start position to the goal (center) and back.

### Maze Layout Example:
![Maze Layout](./images/maze-competition-example.jpg) <!-- Replace this with the actual path to your image -->

## Flood-Fill Algorithm in Action
To solve the maze, we used a **flood-fill algorithm**, which plays a critical role in path planning. Here’s how it works in our robot:

- Initially, all cells in the maze are assigned a value based on their distance from the center (goal).
- The robot scans its surroundings using distance sensors (TOF) and updates the map with known walls.
- Using the flood-fill values, it determines the neighboring cell with the **lowest value** and moves in that direction.
- As the robot discovers new walls, it dynamically updates the maze and recalculates the shortest path to the center.
- Once the center is reached, a final optimal path is computed for a high-speed run.

This method allowed our robot to **continuously explore and optimize** its route, adapting in real-time to the maze layout.

## Team
- **Thanupiriyan Sannithy** (Team Leader)  
- **Tharsan I.**  
- **Kalainilavan I.**

## Features
- Flood-fill-based maze-solving algorithm  
- Real-time sensor-based navigation  
- STM32 microcontroller firmware built with PlatformIO  
- Compact and optimized robot design for tight turns and fast acceleration

## How to Use
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/maze-solving-micromouse-2024.git
