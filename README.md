# Gesture-Controlled Robotic Arm with Computer Vision

Welcome to the Gesture-Controlled Robotic Arm with Computer Vision project! This repository contains code and instructions for building a robotic arm that can be controlled using hand gestures, leveraging the power of OpenCV and Google's MediaPipe Library.

## Overview

This project aims to create a gesture-based control system for a robotic arm using computer vision techniques. The system tracks the movements of the user's hand through a webcam, interprets hand gestures using OpenCV and MediaPipe, and translates these gestures into instructions for the robotic arm to follow.

## Prerequisites

- Python 3.7.x (compatible with versions less than 3.8)
- Arduino IDE
- OpenCV
- MediaPipe
- SerialDevice
- cvzone
- Using PyCharm for development is advisable

## Usage

1. Position your hand in front of the webcam.
2. The system will track the movements of your hand.
3. The robotic arm will replicate the movements of your hand in real-time.
4. To stop the program, make the gesture indicated (index finger open and pinky finger open).

## Implementation

The heart of this project lies in the concept of dividing the webcam's frame into a grid of cells, such as a 2x2 grid. Each cell serves as a Region of Interest (ROI). The Python script then detects the hand's location within one of these cells and generates corresponding instructions for the robotic arm to mimic the movements.

For enhanced precision, you can increase the grid size to 3x3 or 4x4 cells, providing more accurate tracking and control over the robotic arm's movements.

## Benefits

- **Innovative Control:** Utilize natural hand gestures to control the robotic arm.
- **Real-time Interaction:** Experience instant feedback as the robotic arm mirrors your hand movements.
- **Extensible Concept:** This project forms the foundation for advanced gesture-based control applications.
