cmake_minimum_required(VERSION 3.15)
project(MyEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 1. Look inside the src subfolder for source files
file(GLOB SRC_FILES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC_FILES})

# 2. Tell CMake where your header files live
target_include_directories(${PROJECT_NAME} PRIVATE include)
