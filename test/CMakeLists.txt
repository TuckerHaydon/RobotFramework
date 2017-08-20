cmake_minimum_required(VERSION 3.2)

project(TestRobotFramework)
set(CMAKE_CXX_STANDARD 14)

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# Add header files
FILE(GLOB_RECURSE header_list ${CMAKE_SOURCE_DIR}/include/*.h)
FOREACH(file_path ${header_list})
    GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
    include_directories(${dir_path})
ENDFOREACH()

# Make test executable
file(GLOB_RECURSE TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE CODE_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
list(REMOVE_ITEM CODE_SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp)
add_executable(${PROJECT_NAME} ${TEST_SOURCES} ${CODE_SOURCES})
target_link_libraries(${PROJECT_NAME} Catch)

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-g -O0 --coverage -fprofile-arcs -ftest-coverage")
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "--coverage")
