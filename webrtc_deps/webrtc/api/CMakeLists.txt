
project(webrtc_api)

set(SRCS
audio/audio_frame.cc
audio/channel_layout.cc
#field_trials_registry.cc
#rtp_parameters.cc
)

add_library(${PROJECT_NAME} STATIC ${SRCS})