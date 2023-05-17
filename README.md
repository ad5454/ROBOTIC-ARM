# ROBOTIC-ARM
# Gesture-Controlled Robotic Arm with Computer Vision
This repository contains code and instructions for building a robotic arm using OpenCV and Google's [MediaPipe](https://github.com/google/mediapipe) Library.

Can read my article on [Medium](https://medium.com/@aa7865/gesture-controlled-robotic-arm-with-computer-vision-feb63d13056c)
<img align="right" alt="Coding" width="75"
src="https://user-images.githubusercontent.com/92617405/235196114-f17498e9-5ee0-4e18-82fe-abd120029762.gif">

![WhatsApp Image 2023-04-27 at 19 42 06](https://user-images.githubusercontent.com/"C:\Users\naira\OneDrive\Pictures\a11964e0-3a0b-40b0-b2c8-432c2ca96df1.jpg")


The project uses a webcam to track the movements of the user's hand using MediaPipe's Hand Tracking module, and uses this information to control the movements of the robotic arm. The robotic arm is controlled using an Arduino board and servo motors.

## Prerequisites
* Python 3.7.x (it only worked on version less than 3.8)
* Arduino IDE
* OpenCV
* MediaPipe
* SerialDevice
* [cvzone](https://github.com/cvzone/cvzone)
* using pycharm is advisable

## Usage
Position your hand in front of the webcam.

The robotic arm will follow the movements of your hand.

To stop the program, make the the following sign (index finger open and pinky finger open).

## Explanation

<img width="503" alt="Screenshot 2023-04-11 152342" src="https://user-images.githubusercontent.com/92617405/231125223-7d162a43-233b-424c-8401-e9e70664cf9d.png">

To achieve this, you can divide the frame into a 2x2 grid of cells, with each cell representing an ROI. Using a Python script, you can detect the location of your hand within one of these cells and send a set of instructions to the robotic arm to move to a specific coordinate within that cell by changing the degrees of the servo motors for the base, shoulders, and gripper.

While the 2x2 grid provides some freedom of movement, you may need more precision for certain applications. In this case, you can increase the number of cells by creating a 3x3 or 4x4 grid. This will allow for more accurate detection of hand location and greater control over the robotic arm's movements.

Overall, this approach can be useful for a variety of applications where precise control of a robotic arm is required based on the location of an object in an image. You can integrate the Python script with the robotic arm hardware and software to achieve this functionality.

In addition to controlling the movement of the robotic arm based on the location of the hand within an ROI, you can also control the gripper based on whether the palm of the hand is open or closed.



