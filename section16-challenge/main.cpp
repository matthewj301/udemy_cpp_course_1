// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
    
    // Savings 

    Account *sa1 = new Savings_Account("Larry", 1000, 5.0);
    Account *sa2 = new Savings_Account("Moe", 5000);
    Account *sa3 = new Savings_Account("Curly", 2000, 1.8);
    vector<Account *> sav_accounts {sa1, sa2, sa3};

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2500);
   
   // Checking
   
    Account *ca1 = new Checking_Account {} ;
    Account *ca2 = new Checking_Account {"Kirk"} ;
    Account *ca3 = new Checking_Account {"Spock", 2000} ;
    Account *ca4 = new Checking_Account {"Bones", 5000} ;
    vector<Account *> check_accounts {ca1, ca2, ca3, ca4} ;

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust
  
    Account * ta1 = new Trust_Account {};
    Account * ta2 = new Trust_Account {"Athos", 10000, 5.0};
    Account * ta3 = new Trust_Account {"Porthos", 20000, 4.0};
    Account * ta4 = new Trust_Account {"Aramis", 30000};
//
    vector<Account *> trust_accounts {ta1, ta2, ta3, ta4};

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    //
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);
    

    
    return 0;
}

