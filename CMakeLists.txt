#check for minimum required cmake version
cmake_minimum_required(VERSION 3.8)

#set name project and enable programming language for project
project(IGE LANGUAGES C CXX)
set(TARGET IGE)

#set standarts for c c++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

#set c++ flags for compiler
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
#-Wall enabled common warnings
#-Wextra extended warnings
#-Werror warning treat as error
#-Wconversion conversion warning

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(src)