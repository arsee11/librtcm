
project(webrtc_apm_aecm)

set(BASE_SRCS
aecm_core.cc
aecm_core_c.cc
#aecm_core_mips.cc
#aecm_core_neon.cc
echo_control_mobile.cc

)

add_library(${PROJECT_NAME} STATIC ${BASE_SRCS})
