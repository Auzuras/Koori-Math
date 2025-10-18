cmake_minimum_required(VERSION 3.20)

project(KOORI_MATH LANGUAGES CXX)

option(KOORI_MATH_TEST_OPT "Build Koori Math tests" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(KooriMath INTERFACE)

target_include_directories(KooriMath INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include> $<INSTALL_INTERFACE:Include>)

if(KOORI_MATH_TEST_OPT)

    enable_testing()

    add_subdirectory(Tests)

endif()