//
// Created by Matthew Johnson on 10/14/22.
//

#ifndef UDEMY_CPP_COURSE_1_CHECKING_ACCOUNT_H
#define UDEMY_CPP_COURSE_1_CHECKING_ACCOUNT_H
#include "Account.h"

class Checking_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr double withdrawl_fee = 1.5;
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    bool withdraw(double amount);
    // Deposit is inherited
};


#endif //UDEMY_CPP_COURSE_1_CHECKING_ACCOUNT_H
