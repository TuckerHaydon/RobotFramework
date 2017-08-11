## Project Setup
cmake_minimum_required (VERSION 3.2)
project (RobotFramework)
set(CMAKE_CXX_STANDARD 14)

## Main project
# Add header files
FILE(GLOB_RECURSE header_list ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
FOREACH(file_path ${header_list})
    GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
    include_directories(${dir_path})
ENDFOREACH()

# Add source files
FILE(GLOB_RECURSE SRC_FILES src/*.cpp)

# Compile Executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

## Sub-projects
# YAML-cpp whatnot
add_subdirectory(modules/yaml-cpp)

# Unit testing
add_subdirectory(test)

