// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    vector<Checking_Account> check_account;
    check_account.push_back(Checking_Account {} );
    check_account.push_back(Checking_Account {"Superman"} );
    check_account.push_back(Checking_Account {"Batman", 2000} );

    display(check_account);
    deposit(check_account, 1000);
    withdraw(check_account, 2000);

    vector<Trust_Account> t_account;
    t_account.push_back(Trust_Account {} );
    t_account.push_back(Trust_Account {"Superman"} );
    t_account.push_back(Trust_Account {"Batman", 2000} );
    t_account.push_back(Trust_Account {"Wonderwoman", 5000, 5.0} );

    display(t_account);
    deposit(t_account, 30000);
    withdraw(t_account, 2000);
    withdraw(t_account, 2000);
    withdraw(t_account, 2000);
    withdraw(t_account, 2000);

    return 0;
}

