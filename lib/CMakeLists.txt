cmake_minimum_required(VERSION 3.20)
project(infosec_lab_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(infosec_lab SHARED
    src/vcs.cpp
    src/env.cpp
)

target_include_directories(infosec_lab PUBLIC include)
