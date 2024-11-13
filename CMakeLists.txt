cmake_minimum_required(VERSION 3.10)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# For matplotlib-cpp
find_package(sciplot)
find_package (Eigen3 REQUIRED NO_MODULE)
find_package(SndFile REQUIRED)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE Eigen3::Eigen SndFile::sndfile sciplot::sciplot)