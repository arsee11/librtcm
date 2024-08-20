cmake_minimum_required(VERSION 3.5)

project(audio LANGUAGES CXX)

set(AUDIO_SRCS
    ns.cpp
    aec_m.cpp
)

if(${RTCM_AVX2_ENABLE})
    set(AUDIO_SRCS
        aec.cpp
        ${AUDIO_SRCS}
    )
endif()

add_library(${PROJECT_NAME} 
    ${AUDIO_SRCS}
)
