cmake_minimum_required(VERSION 3.5)

project(webrtc_base)

set(BASE_SRCS
experiments/field_trial_parser.cc
memory/aligned_malloc.cc
checks.cc
logging.cc
platform_thread_types.cc
time_utils.cc
string_encode.cc
string_utils.cc
strings/string_builder.cc
race_checker.cc
system_time.cc
)

add_library(${PROJECT_NAME} STATIC ${BASE_SRCS})


