cmake_minimum_required(VERSION 3.23)
project(udemy_cpp_course_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(udemy_course_1 section13-challenge/main.cpp section13-challenge/Movie.cpp
        section13-challenge/Movies.cpp section13-challenge/Movies.h)
