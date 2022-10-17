//
// Created by Matthew Johnson on 10/17/22.
//

#include "InsufficentFundsException.h"

const char *InsufficentFundsException::what() const noexcept {
    return "Insufficient funds.";
}