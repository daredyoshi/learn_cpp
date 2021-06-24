# Specify the minimum version of Cmake that can run this script
cmake_minimum_required(VERSION 3.19)

# Project name and version
project(serialization VERSION 1.0)
# Request C++ 11 standard features
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(serialization "${PROJECT_SOURCE_DIR}/src/")
file(GLOB SOURCES "src/*cpp")

# Compile the passed source files into an executable
add_executable(serialization ${SOURCES}) 

# Set the output director for executables
set_target_properties(serialization PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>")
target_compile_features(serialization PUBLIC cxx_std_11)

# add compiler warning flags just when building this project
# via the BUILD_INTERFACE generator expression
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

set(gcc_flags "-Wall;-Werror;-Wunused;-Wextra;-Wshadow;-Wshadow;-Wformat=2;-pedantic-errors;-std=c++17")
set(msvc_flags "-W3")

target_compile_options(serialization PRIVATE
   "$<${gcc_like_cxx}:$<BUILD_INTERFACE:${gcc_flags}>>"
   "$<${msvc_cxx}: $<BUILD_INTERFACE:${msvc_flags}>>")


