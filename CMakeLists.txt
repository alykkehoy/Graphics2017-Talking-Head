cmake_minimum_required(VERSION 3.8)
project(OpenGLPractice)

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)
include_directories(glad/include)

set(SOURCE_FILES main.cpp glad/src/glad.c)
set(CMAKE_CXX_STANDARD 11)

add_executable(OpenGLPractice ${SOURCE_FILES})

target_link_libraries(OpenGLPractice glfw gdi32 opengl32)
target_link_libraries(OpenGLPractice ${OPENGL_gl_LIBRARY})