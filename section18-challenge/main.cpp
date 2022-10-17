#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    // test your code here
    try {
        std::unique_ptr<Account> act = std::make_unique<Checking_Account>("moe", -100.0);
    }
    catch (const IllegalBalanceException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    try {
        std::unique_ptr<Account> act = std::make_unique<Checking_Account>("moe", 100.0);
        act->withdraw(200.0);
    }
    catch (const InsufficentFundsException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

