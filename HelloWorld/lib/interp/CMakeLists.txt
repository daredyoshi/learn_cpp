# lib/interp/CMakeLists.txt
# Compile shared library frmo source files
add_library(interp interpolate.cpp)

# State that any target ilnking to this library can see
# the pssed source directories
target_include_directories(interp
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
