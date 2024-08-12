
project(webrtc_deps)


add_subdirectory(webrtc)

set(SRCS
absl_inl/absl/strings/ascii.cc
)

add_library(${PROJECT_NAME} STATIC ${SRCS})

