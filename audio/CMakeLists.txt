cmake_minimum_required(VERSION 3.5)

project(audio LANGUAGES CXX)

add_library(${PROJECT_NAME} 
    ns.cpp
    aec.cpp
)
