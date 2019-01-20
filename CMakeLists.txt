cmake_minimum_required(VERSION 3.0)
#set(CMAKE_VERBOSE_MAKEFILE ON)

# delete cmake cache folder before changing a build setting/option
set(BUILD_LINUX OFF CACHE BOOL "Build with SDL2 support")
set(BUILD_WINDOWS OFF CACHE BOOL "Build with Windows support (msys/mingw64)")
set(BUILD_VITA OFF CACHE BOOL "Build with Ps Vita support")
set(BUILD_PS3 OFF CACHE BOOL "Build with PS3 support")
set(BUILD_3DS OFF CACHE BOOL "Build with 3DS support")
set(BUILD_SWITCH OFF CACHE BOOL "Build with Nintendo Switch support")

# add libcross2d library
add_subdirectory(libcross2d)
add_subdirectory(Box2D)

# required for cmake toolchain setup
project(cross2d-examples)

# examples
add_subdirectory(examples/pinball)
