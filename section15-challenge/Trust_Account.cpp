#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
: Savings_Account (name, balance, int_rate) {}


bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold) {
        amount += bonus_amount;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if (amount > (balance * max_withdraw_percent)) {
        std::cout << "Exceeds maximum withdrawl amount" << std::endl;
        return false;
    }
    if (num_withdrawals >= max_withdrawals) {
        std::cout << "Cannot withdraw more than " << max_withdrawals << " times" << std::endl;
        return false;
    }
    Account::withdraw(amount);
    num_withdrawals++;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

