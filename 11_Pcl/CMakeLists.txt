cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(11_Pcl)

find_package(PCL REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcd_demo src/pcd_demo.cpp)
target_link_libraries(
    pcd_demo
    ${PCL_LIBRARIES}
)
