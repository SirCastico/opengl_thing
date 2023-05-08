cmake_minimum_required (VERSION 3.20)

add_executable(yep main.cpp gl_renderer.cpp)

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(yep PUBLIC SDL2::SDL2main)
endif()

target_link_libraries(yep PUBLIC glm::glm SDL2::SDL2 OpenGL::OpenGL glad)
