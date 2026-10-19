
cmake_minimum_required(VERSION 3.20)

project(BoardCheck
    VERSION 0.1.0
    DESCRIPTION "PCB visual inspection using C++ and OpenCV"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV REQUIRED)

add_executable(BoardCheck
    src/main.cpp
)

target_include_directories(BoardCheck
    PRIVATE
        ${OpenCV_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(BoardCheck
    PRIVATE
        ${OpenCV_LIBS}
)

message(STATUS "BoardCheck version: ${PROJECT_VERSION}")
message(STATUS "OpenCV version: ${OpenCV_VERSION}")
