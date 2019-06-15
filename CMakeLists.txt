cmake_minimum_required(VERSION 2.8.12)

project(kkmeans)

include(dlib-19.6/dlib/cmake)

add_executable(kkmeans kkmeans.cpp)

target_link_libraries(kkmeans dlib::dlib)

