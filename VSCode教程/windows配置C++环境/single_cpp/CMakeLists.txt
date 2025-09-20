# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目的名称
project(HelloWorld)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 指定源文件,生成的可执行文件名称为hello_world.exe
add_executable(hello_world hello_world.cpp)


