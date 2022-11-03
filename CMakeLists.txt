cmake_minimum_required(VERSION 3.13)

project(NonogramSolver VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER g++)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_executable(NonogramSolver main.cpp)
target_link_libraries(NonogramSolver src)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED SDL2_image>=2.0.0)
target_include_directories(NonogramSolver PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(NonogramSolver PUBLIC "${PROJECT_BINARY_DIR}/src")

target_include_directories(NonogramSolver PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(NonogramSolver ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})


add_subdirectory(src)