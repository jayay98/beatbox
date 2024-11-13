cmake_minimum_required(VERSION 3.10)

project(HelloWorld)

find_package (Eigen3 REQUIRED NO_MODULE)
find_package(SndFile REQUIRED)

add_executable(HelloWorld src/main.cpp)

target_link_libraries(HelloWorld PRIVATE Eigen3::Eigen SndFile::sndfile)