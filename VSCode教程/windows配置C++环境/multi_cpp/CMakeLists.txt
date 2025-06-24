cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Calculator)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

# Add compile options for debugging
add_compile_options(-g)

# Add the include directory
#"在编译时，请额外搜索项目目录下的 include 文件夹来寻找头文件"
include_directories(include)

# Add the executable
add_executable(calculator main.cpp src/Calculator.cpp)