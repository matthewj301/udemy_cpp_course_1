// Section 16
// Interfaces - complete

#include <iostream>

class Printable {
    friend std::ostream &operator<<(std::ostream &os, const Printable &obj);

public:
    virtual void print(std::ostream &os) const = 0;

    virtual ~Printable() = default;

};

std::ostream &operator<<(std::ostream &os, const Printable &obj) {
    obj.print(os);
    return os;
}

class Account : public Printable {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }

    void print(std::ostream &os) const override {
        os << "Account display";
    }

    ~Account() override {}
};

class Checking : public Account {
public:
    void withdraw(double amount) override {
        std::cout << "In Checking::withdraw" << std::endl;
    }

    void print(std::ostream &os) const override {
        os << "Checking display";
    }

    ~Checking() override = default;
};


class Savings : public Account {
public:
    void withdraw(double amount) override {
        std::cout << "In Savings::withdraw" << std::endl;
    }

    void print(std::ostream &os) const override {
        os << "Savings display";
    }

    ~Savings() override = default;
};

class Trust : public Account {
public:
    void withdraw(double amount) override {
        std::cout << "In Trust::withdraw" << std::endl;
    }

    void print(std::ostream &os) const override {
        os << "Trust display";
    }

    ~Trust() override = default;
};

int main() {

    auto *p1 = new Account();
    std::cout << *p1 << std::endl;

    Account *p2 = new Checking();
    std::cout << *p2 << std::endl;

//    Account a;
//    std::cout << a<< std::endl;
//    
//    Checking c;
//    std::cout << c << std::endl;
//
//    Savings s;
//    std::cout << s << std::endl;
//    
//    Trust t;
//    std::cout << t << std::endl;

    delete p1;
    delete p2;
    return 0;
}
