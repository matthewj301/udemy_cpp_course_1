//
// Created by Matthew Johnson on 10/16/22.
//
#include <iostream>
#include "Printable.h"

std::ostream &operator<<(std::ostream &os, const Printable &obj) {
    obj.print(os);
    return os;
}