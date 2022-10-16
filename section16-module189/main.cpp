// Section 16
// Virtual destructors

#include <iostream>
#include "vector"

// This class uses dynamic polymorphism for the withdraw method
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }

    virtual ~Account() { std::cout << "Account:: destructor" << std::endl; }
};

class Checking : public Account {
public:
    void withdraw(double amount) override {
        std::cout << "In Checking::withdraw" << std::endl;
    }

    ~Checking() override { std::cout << "Checking:: destructor" << std::endl; }

};

class Savings : public Account {
public:
    void withdraw(double amount) override {
        std::cout << "In Savings::withdraw" << std::endl;
    }

    ~Savings() override { std::cout << "Savings:: destructor" << std::endl; }

};

class Trust : public Account {
public:
    void withdraw(double amount) override {
        std::cout << "In Trust::withdraw" << std::endl;
    }

    ~Trust() override { std::cout << "Trust:: destructor" << std::endl; }
};

void do_withdraw(Account &acct, double amount) {
    acct.withdraw(amount);
    std::cout << "Withdrawn " << amount << std::endl;
}

int main() {

    Account a;
    Checking b;
    Savings c;
    Trust d;

    std::vector<Account *> accounts {&a, &b, &c, &d};

    for (auto acct_ptr: accounts) {
        do_withdraw(*acct_ptr, 1000);
    }



    return 0;
}

