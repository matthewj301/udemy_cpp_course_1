cmake_minimum_required(VERSION 3.23)
project(udemy_cpp_course_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(udemy_course_1 section18-challenge/Account.cpp
        section18-challenge/Account.h
        section18-challenge/Account_Util.cpp
        section18-challenge/Account_Util.h
        section18-challenge/Checking_Account.cpp
        section18-challenge/Checking_Account.h
        section18-challenge/I_Printable.cpp
        section18-challenge/I_Printable.h
        section18-challenge/IllegalBalanceException.h
        section18-challenge/main.cpp
        section18-challenge/Savings_Account.cpp
        section18-challenge/Savings_Account.h
        section18-challenge/Trust_Account.cpp
        section18-challenge/Trust_Account.h section18-challenge/IllegalBalanceException.cpp section18-challenge/InsufficentFundsException.h section18-challenge/InsufficentFundsException.cpp)