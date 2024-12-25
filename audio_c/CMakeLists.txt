cmake_minimum_required(VERSION 3.5)

project(audio_c LANGUAGES CXX)

set(AUDIO_SRCS
    audio_d.cpp
    internal/audio_d_factory.cpp
    internal/g711_d.cpp
)

add_library(${PROJECT_NAME} 
    ${AUDIO_SRCS}
)
