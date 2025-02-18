cmake_minimum_required(VERSION 3.5)

project(rtcm LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#set(CMAKE_CXX_FLAGS " --std=c++20 -fPIC -g -fpermissive -march=haswell -fsanitize=address ${CMAKE_CXX_FLAGS}")
#set(CMAKE_C_FLAGS  "-fPIC -march=haswell -fsanitize=address ${CMAKE_C_FLAGS}")

set(RTCM_AVX2_ENABLE ON)
if(${RTCM_AVX2_ENABLE})
    set(CMAKE_CXX_FLAGS " --std=c++20 -fPIC -g -fpermissive -mfma -march=haswell ${CMAKE_CXX_FLAGS}")
    set(CMAKE_C_FLAGS  "-fPIC -mfma -march=haswell ${CMAKE_C_FLAGS}")
else()
    set(CMAKE_CXX_FLAGS " --std=c++20 -fPIC -g -fpermissive -mfma ${CMAKE_CXX_FLAGS}")
    set(CMAKE_C_FLAGS  "-fPIC -mfma ${CMAKE_C_FLAGS}")
endif()

find_package(PkgConfig)
pkg_search_module(WEBRTC REQUIRED webrtc_more)
message("webrtc_more found dir:${WEBRTC_INCLUDE_DIRS}")

add_definitions(-D WEBRTC_POSIX)
add_definitions(-D WEBRTC_USE_EPOLL)
add_definitions(-D WEBRTC_LINUX)
add_definitions(-D _M_X64)
add_definitions(-D WEBRTC_ENABLE_AVX2)
add_definitions(-D WEBRTC_APM_DEBUG_DUMP=0)

include_directories(${WEBRTC_INCLUDE_DIRS} )
include_directories(${WEBRTC_INCLUDE_DIRS}/absl_inl/absl)
include_directories(${WEBRTC_INCLUDE_DIRS}/webrtc)

include_directories(${PROJECT_SOURCE_DIR})


add_subdirectory(webrtc_deps/)
add_subdirectory(audio_c/)
add_subdirectory(audio_p/)

add_library(${PROJECT_NAME} SHARED none.cpp)         

set(DEP_LIBS
    audio_c
    audio_p
    webrtc_audio_codecs
    webrtc_base    
    webrtc_system_wrappers
    webrtc_apm_ns
    webrtc_apm_aecm
    webrtc_apm_vad
    webrtc_audio_processing
    webrtc_api
    webrtc_common_audio
    webrtc_absl_deps 
)

if(${RTCM_AVX2_ENABLE})
    set(DEP_LIBS
        webrtc_apm_aec3
        ${DEP_LIBS}
    )
endif()

target_link_libraries(${PROJECT_NAME} 
    -Wl,--whole-archive
    ${DEP_LIBS}
    -Wl,--no-whole-archive
)

target_compile_definitions(${PROJECT_NAME} PRIVATE LIBRTCW_LIBRARY)
