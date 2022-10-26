cmake_minimum_required(VERSION 3.23)
project(udemy_cpp_course_1)

set(CMAKE_CXX_STANDARD 14)
add_executable(udemy_course_1 section23-module289/main.cpp)

find_package(Boost REQUIRED)
if(Boost_FOUND)
    message("Boost Found")
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(udemy_course_1 ${Boost_LIBRARIES})
elseif(NOT Boost_FOUND)
    error("Boost Not Found")
endif()

