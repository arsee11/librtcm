
project(webrtc_api)

set(SRCS
audio/audio_frame.cc
audio/channel_layout.cc
audio/echo_canceller3_config.cc
#field_trials_registry.cc
#rtp_parameters.cc
)

add_library(${PROJECT_NAME} STATIC ${SRCS})