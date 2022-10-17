//
// Created by Matthew Johnson on 10/17/22.
//
#include "IllegalBalanceException.h"

const char *IllegalBalanceException::what() const noexcept {
    return "Cannot create an account with a negative balance";
}