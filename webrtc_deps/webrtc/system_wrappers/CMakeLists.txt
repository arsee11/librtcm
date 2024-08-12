
project(webrtc_system_wrappers)


set(SRCS
source/cpu_features.cc
)

add_library(${PROJECT_NAME} STATIC ${SRCS})

