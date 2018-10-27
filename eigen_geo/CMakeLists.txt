cmake_minimum_required( VERSION 2.8 )
project( geometry )

# 添加Eigen头文件
include_directories( "/usr/include/eigen3" )

add_executable( robot_trans robot_trans.cpp )
add_executable( chapter3_5 chapter3_5.cpp )
