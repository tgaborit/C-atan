cmake_minimum_required(VERSION 3.13)

project(catane)

find_package(SDL2 REQUIRED)

add_executable(catane catane.c)

if (SDL2_FOUND)
    target_include_directories(catane PUBLIC ${SDL2_INCLUDE_DIRS})
    target_link_libraries (catane ${SDL2_LIBRARIES})
else()
    message(FATAL_ERROR "libsdl2-dev not found")
endif ()