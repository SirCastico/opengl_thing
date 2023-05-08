cmake_minimum_required (VERSION 3.20)

project("OpenGl_Thing")

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

add_subdirectory(third_party)
add_subdirectory(src)

