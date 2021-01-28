# Specify the minimum version of Cmake that can run this script
cmake_minimum_required(VERSION 3.19)

# Project name and version
project(HelloWorld VERSION 1.0)
# Request C++ 11 standard features
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
add_subdirectory(lib/interp)

configure_file(include/Config.h.in
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Config.h")


# Compile the passed source files into an executable
add_executable(HelloWorld "${CMAKE_CURRENT_SOURCE_DIR}/src/HelloWorld.cpp")
add_executable(EnterNumber "${CMAKE_CURRENT_SOURCE_DIR}/src/EnterNumber.cpp")

target_link_libraries(HelloWorld interp)

target_include_directories(HelloWorld PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Set the output director for executables
set_target_properties(HelloWorld PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>")
set_target_properties(EnterNumber PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>")


target_compile_features(HelloWorld PUBLIC cxx_std_11)
target_compile_features(EnterNumber PUBLIC cxx_std_11)

# add compiler warning flags just when building this project
# via the BUILD_INTERFACE generator expression
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

set(gcc_flags "-Wall;-Werror;-Wunused;-Wextra;-Wshadow;-Wshadow;-Wformat=2;-pedantic-errors;-std=c++17")
set(msvc_flags "-W3")

target_compile_options(HelloWorld PRIVATE
   "$<${gcc_like_cxx}:$<BUILD_INTERFACE:${gcc_flags}>>"
   "$<${msvc_cxx}: $<BUILD_INTERFACE:${msvc_flags}>>")

target_compile_options(EnterNumber PRIVATE
   "$<${gcc_like_cxx}:$<BUILD_INTERFACE:${gcc_flags}>>"
   "$<${msvc_cxx}: $<BUILD_INTERFACE:${msvc_flags}>>")

