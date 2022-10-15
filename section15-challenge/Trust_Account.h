#ifndef UDEMY_CPP_COURSE_1_TRUST_ACCOUNT_H
#define UDEMY_CPP_COURSE_1_TRUST_ACCOUNT_H
#include "Savings_Account.h"

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr double bonus_amount = 50.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;

protected:
    int num_withdrawals = 0;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    // Inherits the Account::deposit methods
    // If deposit amount >= 5000 then bonus of 50 is added
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif //UDEMY_CPP_COURSE_1_TRUST_ACCOUNT_H
