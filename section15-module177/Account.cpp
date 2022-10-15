#include "Account.h"
// Simple Account class

Account::Account()
:Account(0.0) {}

Account::Account(double balance)
: balance(balance) {}

void Account::deposit(double amount) {
    std::cout << "Depositing " << amount << " to account" << std::endl;
    balance += amount;
}

void Account::withdraw(double amount) {
    std::cout << "Withdrawing " << amount << " from account" << std::endl;
    if (balance - amount >= 0) {
        balance -= amount;
    } else {
        std::cout << "Insufficient funds" << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Account &account) {
    os <<  "Account balance: " << account.balance;
    return os;
}
