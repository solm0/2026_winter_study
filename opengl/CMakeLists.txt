cmake_minimum_required(VERSION 3.10)
project(test)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)

add_executable(test
    src/main-f.cpp
    src/gl.c
)

target_include_directories(test PRIVATE include)

target_link_libraries(test
    glfw
    "-framework OpenGL"
)