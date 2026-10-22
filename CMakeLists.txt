
cmake_minimum_required(VERSION 3.20)

project(BoardCheck
    VERSION 0.1.0
    DESCRIPTION "PCB visual inspection using C++ and OpenCV"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.7.2
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(CLI11)

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
        CLI11::CLI11
)

message(STATUS "BoardCheck version: ${PROJECT_VERSION}")
message(STATUS "OpenCV version: ${OpenCV_VERSION}")
