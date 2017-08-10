cmake_minimum_required (VERSION 3.2)
project (RobotFramework)

add_subdirectory(submodules/yaml-cpp)
include_directories(include)

add_executable(${PROJECT_NAME} src/main.cpp)
