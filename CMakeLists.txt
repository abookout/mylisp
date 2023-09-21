cmake_minimum_required(VERSION 3.10)

# Set the project name
project(mylisp)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/lib)

# Add source files from the src directory
file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})
