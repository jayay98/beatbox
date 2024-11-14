cmake_minimum_required(VERSION 3.10)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package (Eigen3 REQUIRED NO_MODULE)
find_package(SndFile REQUIRED)
find_path(MATPLOTLIB_CPP_INCLUDE_DIRS "matplotlibcpp.h")
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

add_executable(main src/main.cpp)
target_compile_definitions(main PRIVATE WITHOUT_NUMPY)
target_include_directories(main PRIVATE ${Python3_INCLUDE_DIRS} ${MATPLOTLIB_CPP_INCLUDE_DIRS})
target_link_libraries(main PRIVATE Eigen3::Eigen SndFile::sndfile Python3::Python Python3::Module)