cmake_minimum_required(VERSION 3.3)
project(CurrencyDetect)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("/usr/local/include")
include_directories("/Users/pradeepwason/Downloads/vlfeat-0.9.20/")

link_directories("/Users/pradeepwason/Downloads/vlfeat-0.9.20/bin/maci64")

find_package(OpenCV)

set(SOURCE_FILES main.cpp)
add_executable(CurrencyDetect ${SOURCE_FILES})

target_link_libraries(CurrencyDetect
        ${OpenCV_LIBRARIES}
        "-lvl"
)

