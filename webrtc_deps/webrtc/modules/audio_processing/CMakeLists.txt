
project(webrtc_audio_processing)

add_subdirectory(ns)


set(SRCS
audio_buffer.cc
#audio_processing_builder_impl.cc
#audio_processing_impl.cc
#echo_control_mobile_impl.cc
#gain_control_impl.cc
#gain_controller2.cc
#high_pass_filter.cc
#residual_echo_detector.cc
#rms_level.cc
splitting_filter.cc
three_band_filter_bank.cc

)

add_library(${PROJECT_NAME} STATIC ${SRCS})