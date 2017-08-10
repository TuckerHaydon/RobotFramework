[![Build Status](https://travis-ci.org/TuckerHaydon/RobotFramework.svg?branch=master](https://travis-ci.org/TuckerHaydon/RobotFramework)


# Goal
The goal of this project is to create an object-oriented framework for a simple 2-wheel robot. The software should be abstracted away from and ignorant of the hardware. Furthermore, the sotware should be unit-tested as much as possible. The majority of this project will be completed in C++ 14 using modern C++ standards and functions.

# Software Components
## Unit Testing
[Catch](https://github.com/philsquared/Catch) is used to unit test this framework.

## Separation of Software and Hardware
Apart from an initial configuration, the majority of the software should be ignorant of the hardware. The goal is to create a robust software framework that can be easily adapted to suit a given 2-wheel robot framework. 

Of course certain components of the software must know about the hardware. I designate these as Drivers and configure them during initialization. These driver objects interface with the hardware and return standard, hardware-independent messages. For example, an encoder driver returns a message containing the speed of a wheel in cm/s. Cm/s is chosen so that other parts of the software that need to know the robot's speed do not need to know the radius or diameter of a wheel. 

## Design Paradigms
* Inversion of Control

# Building This Project
Cmake is used to build this project.

# Configuring This Project
A YAML config file in the 'config' directory is used to configure this project.

# Dependencies
* Cmake
* [yaml-cpp](https://github.com/jbeder/yaml-cpp)

# Travis
[Travis CI](https://travis-ci.org) is used for continuous integration testing.

# Coveralls
[Coveralls](https://coveralls.io) is used for continuous integration code coverage.
