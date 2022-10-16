cmake_minimum_required(VERSION 3.23)
project(udemy_cpp_course_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(udemy_course_1 section16-challenge/Checking_Account.h
        section16-challenge/Account_Util.cpp
        section16-challenge/Account_Util.h
        section16-challenge/Account.h
        section16-challenge/Account.cpp
        section16-challenge/Checking_Account.cpp
        section16-challenge/Savings_Account.cpp
        section16-challenge/main.cpp
        section16-challenge/Savings_Account.h
        section16-challenge/Trust_Account.cpp
        section16-challenge/Trust_Account.h section16-challenge/Printable.h section16-challenge/Printable.cpp)