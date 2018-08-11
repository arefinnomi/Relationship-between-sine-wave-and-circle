cmake_minimum_required(VERSION 2.6)
project(Sinewave)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(MY_HEADER_FILES
        include/draw.h
        include/point.h
        )

set(MY_SOURCE_FILES
        main.cpp
        )

include_directories(

)
add_executable(Sinewave
        ${MY_HEADER_FILES}
        ${MY_SOURCE_FILES}
        )
target_link_libraries(Sinewave
        ${OPENGL_LIBRARY} # filled by "find_package(OpenGL REQUIRED)"
        ${GLUT_LIBRARY}
        )


