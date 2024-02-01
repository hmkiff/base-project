cmake_minimum_required(VERSION 3.0.0)
project(base_project VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Source files
add_executable( base_project 
                src/main.cpp
                src/glad.c
                libraries/include/glad.h

)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# GLFW setup. Default no docs, tests, or examples.
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libraries/lib/glfw-3.3.9)
target_link_libraries(${PROJECT_NAME} glfw)

# OpenGL setup
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)


include(CPack)

