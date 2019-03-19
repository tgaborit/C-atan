cmake_minimum_required(VERSION 3.13)

project(catane)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(catane catane.c)

if (SDL2_FOUND)
    target_include_directories(catane PUBLIC ${SDL2_INCLUDE_DIRS})
    target_link_libraries (catane ${SDL2_LIBRARIES})
else()
    message(FATAL_ERROR "libsdl2-dev not found")
endif ()

if (SDL2_IMAGE_FOUND)
    target_include_directories(catane PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})
    target_link_libraries (catane ${SDL2_IMAGE_LIBRARIES})
else()
    message(FATAL_ERROR "libsdl2-image-dev not found")
endif ()