//
// Created by Matthew Johnson on 10/16/22.
//
#include <iostream>

#ifndef UDEMY_CPP_COURSE_1_PRINTABLE_H
#define UDEMY_CPP_COURSE_1_PRINTABLE_H
class Printable {
    friend std::ostream &operator<<(std::ostream &os, const Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~Printable() = default;
};

#endif //UDEMY_CPP_COURSE_1_PRINTABLE_H
