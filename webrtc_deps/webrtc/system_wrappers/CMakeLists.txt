
project(webrtc_system_wrappers)


set(SRCS
source/cpu_features.cc
source/field_trial.cc
source/metrics.cc
)

add_library(${PROJECT_NAME} STATIC ${SRCS})

