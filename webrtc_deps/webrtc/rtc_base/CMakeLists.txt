cmake_minimum_required(VERSION 3.5)

project(webrtc_base)

set(BASE_SRCS
memory/aligned_malloc.cc
checks.cc
logging.cc
time_utils.cc
string_encode.cc
string_utils.cc
strings/string_builder.cc
platform_thread_types.cc
system_time.cc
)

add_library(${PROJECT_NAME} STATIC ${BASE_SRCS})


