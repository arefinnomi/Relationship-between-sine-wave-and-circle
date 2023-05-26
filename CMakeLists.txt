cmake_minimum_required(VERSION 3.15)
project(SineWave)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Include directories
include_directories(include ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

# Add source files
set(SOURCES
        main.cpp
        include/draw.h
        include/point.h
        )

# Create executable
add_executable(SineWave ${SOURCES})

# Link libraries
target_link_libraries(SineWave
        ${OPENGL_LIBRARY} # filled by "find_package(OpenGL REQUIRED)"
        glut
        )


