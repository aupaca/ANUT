cmake_minimum_required(VERSION 3.14.5)
project(anut)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB SRC_FILES
    "${SRC_DIR}/system/*.cpp"
    "${SRC_DIR}/vendor/*.cpp"
    "${SRC_DIR}/graphics/gles/*.cpp"
    "${SRC_DIR}/geometry/*.cpp"
    "${SRC_DIR}/math/*.cpp"
)

add_library(anut OBJECT "${SRC_FILES}")
set_property(TARGET anut PROPERTY POSITION_INDEPENDENT_CODE ON)
target_compile_options(anut PUBLIC -O3 -mfpu=neon -mfloat-abi=softfp)
target_link_libraries(anut PUBLIC GLESv3 EGL android)

target_include_directories(anut PRIVATE 
    "${SRC_DIR}/"
)

target_include_directories(anut INTERFACE
    "${SRC_DIR}/"
    "${CMAKE_CURRENT_SOURCE_DIR}/master/"
)

