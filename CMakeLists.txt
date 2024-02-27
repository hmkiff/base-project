cmake_minimum_required(VERSION 3.11.0)
project(base_project VERSION 0.1.0 LANGUAGES C CXX)

# fetch glm library
include(FetchContent)
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        origin/master
)
FetchContent_MakeAvailable(glm)

include(CTest)

enable_testing()

# Source files
add_executable( base_project             
    src/main.cpp
    src/square.cpp
    src/include/square.h
    src/shader.cpp
    src/include/shader.h

)

# glm link library
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# Glad setup
add_library(glad
    libraries/include/glad/src/glad.c
    libraries/include/glad/include/glad/glad.h
    libraries/include/glad/include/KHR/khrplatform.h
)

target_include_directories(glad PUBLIC libraries/include/glad/include)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)

# OpenGL setup
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)


# GLFW setup. Default no docs, tests, or examples.
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libraries/lib/glfw-3.3.9)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)





include(CPack)

