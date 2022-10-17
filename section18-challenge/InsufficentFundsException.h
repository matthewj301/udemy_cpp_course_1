//
// Created by Matthew Johnson on 10/17/22.
//

#ifndef UDEMY_CPP_COURSE_1_INSUFFICENTFUNDSEXCEPTION_H
#define UDEMY_CPP_COURSE_1_INSUFFICENTFUNDSEXCEPTION_H

#include <exception>

class InsufficentFundsException: public std::exception
{
public:
    InsufficentFundsException() noexcept = default;
    ~InsufficentFundsException() override = default;
    const char* what() const noexcept override;
};
#endif //UDEMY_CPP_COURSE_1_INSUFFICENTFUNDSEXCEPTION_H
