# docker based UKF
## tools.cpp file calculates the rmse of the estimation and ground truth data. It is pretty similar with EKF part.

## ukf.h 
* ( in this header file I added a R_radar, R_lidar for convenient.

## ukf.cpp
* I added many string output to debug the code.
### initialization part
* initialize the necessary parameters of code. some parameters need to be tuned
### process measurement part
* both of sensors(lidar, and radar ), their prediction step are same. However their update process are different. So in processmeasurement part, I made a whole code flow which can run same prediction code but run different update steps.
### prediction part
* augmented state generation
* generat sigma points
* make prediction based on the motion model
### update radar part
* radar gets 3 data. The measurement transition matrix is totally nonlinear. So the nonlinear function were made. using the sigma points which were predicted in prediction step. Based on the UKF functions, updating the x prediction and p prediction that are used in next step.
### update lidar
* lidar gets 2data. The measurement transition matrix is linear so the linear function were implemented.By using the sigma points from X state prediction step, Z prediction(sigma points) and mean of zprediction , measurement error can be calculated.Then, by using z error and x error , correlation matrix and Kalman gain can be calculated. Then same with update radar part, updating the x prediction and p prediction that are used in next step.


### Simulation result is showed as below figure. 
RMSE: 
X: 0.0690
Y: 0.0830
VX: 0.3336
VY: 0.2344

![UKF result1](https://github.com/Fred159/Udacity-Term2-Project2-UKF/blob/master/simulator%20result.png)

in more detail graph , zoom in figure is shown as below.

![UKF result2](https://github.com/Fred159/Udacity-Term2-Project2-UKF/blob/master/simulator%20result2.png)

Reference 
1. darienmt
2. NikolasEnt
3. mvirgo
4. Udacity course
5. Docker

Resource
1. Docker images issue
https://medium.com/@flaaud159/udacity-self-driving-car-term2-extended-kalman-filter-project-environment-setting-6861f81cebad
2. Docker based Project utility(Co-work relationship gragh)
* Visual studio 2017
* Docker for windows
* github for windows
![Docker,VS,Github Co-work relationship gragh](https://github.com/Fred159/EKF/blob/master/Docker%20VS%20git%20co%20work.png)

# Unscented Kalman Filter Project Starter Code
Self-Driving Car Engineer Nanodegree Program

In this project utilize an Unscented Kalman Filter to estimate the state of a moving object of interest with noisy lidar and radar measurements. Passing the project requires obtaining RMSE values that are lower that the tolerance outlined in the project rubric. 

This project involves the Term 2 Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases)

This repository includes two files that can be used to set up and intall [uWebSocketIO](https://github.com/uWebSockets/uWebSockets) for either Linux or Mac systems. For windows you can use either Docker, VMware, or even [Windows 10 Bash on Ubuntu](https://www.howtogeek.com/249966/how-to-install-and-use-the-linux-bash-shell-on-windows-10/) to install uWebSocketIO. Please see [this concept in the classroom](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/16cf4a78-4fc7-49e1-8621-3450ca938b77) for the required version and installation scripts.

Once the install for uWebSocketIO is complete, the main program can be built and ran by doing the following from the project top directory.

1. mkdir build
2. cd build
3. cmake ..
4. make
5. ./UnscentedKF

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

Note that the programs that need to be written to accomplish the project are src/ukf.cpp, src/ukf.h, tools.cpp, and tools.h

The program main.cpp has already been filled out, but feel free to modify it.

Here is the main protcol that main.cpp uses for uWebSocketIO in communicating with the simulator.


INPUT: values provided by the simulator to the c++ program

["sensor_measurement"] => the measurment that the simulator observed (either lidar or radar)


OUTPUT: values provided by the c++ program to the simulator

["estimate_x"] <= kalman filter estimated position x
["estimate_y"] <= kalman filter estimated position y
["rmse_x"]
["rmse_y"]
["rmse_vx"]
["rmse_vy"]

---

## Other Important Dependencies
* cmake >= 3.5
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./UnscentedKF` Previous versions use i/o from text files.  The current state uses i/o
from the simulator.

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html) as much as possible.

## Generating Additional Data

This is optional!

If you'd like to generate your own radar and lidar data, see the
[utilities repo](https://github.com/udacity/CarND-Mercedes-SF-Utilities) for
Matlab scripts that can generate additional data.

## Project Instructions and Rubric

This information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/c3eb3583-17b2-4d83-abf7-d852ae1b9fff/concepts/f437b8b0-f2d8-43b0-9662-72ac4e4029c1)
for instructions and the project rubric.

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

