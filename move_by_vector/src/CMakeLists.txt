add_subdirectory("math")

add_executable(main main.cpp)
target_link_libraries(main Point3d)
target_link_libraries(main Vector3d)
