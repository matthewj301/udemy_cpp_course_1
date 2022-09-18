// Section 8 Challenge
/*
	For this program I will be using US dollars and change_amount.
	
    Write a program that asks the user to enter the following:
	An integer representing the number of change_amount 
    	
	You may assume that the number of change_amount entered is greater than or equal to zero
    
	The program should then display how to provide that change to the user.
	
	In the US:
		1 dollar is 100 change_amount
		1 quarter is 25 change_amount
		1 dime is 10 change_amount
		1 nickel is 5 change_amount, and
		1 penny is 1 cent.
		
	Here is a sample run:
	
	Enter an amount in change_amount :  92
	
	You can provide this change as follows:
	dollars    : 0
	quarters : 3
	dimes     : 1
	nickels   : 1
	pennies  : 2
	
	Feel free to use your own currency system.
	Also, think of how you might solve the problem using the modulo operator.

	Have fun and test your program!!

*/
#include <iostream>

using namespace std;

int main() {
    int change_amount {};
    cout << "Enter the number of cents: ";
    cin >> change_amount;
    const int dollar_value {100}, quarter_value {25}, dime_value {10}, nickel_value {5}, penny_value {1};
    int balance {}, dollars {}, quarters {}, dimes {}, nickels {}, pennies {};

    dollars = change_amount / dollar_value;
    balance = change_amount % dollar_value;

    quarters = balance / quarter_value;
    balance %= quarter_value;

    dimes = balance / dime_value;
    balance %= dime_value;

    nickels = balance / nickel_value;
    balance %= nickel_value;

    pennies = balance;

    cout << "You can provide this change as follows: " << endl;
    cout << "dollars: " << dollars << endl;
    cout << "quarters: " << quarters << endl;
    cout << "dimes: " << dimes << endl;
    cout << "nickels: " << nickels << endl;
    cout << "pennies: " << pennies << endl;
    cout << endl;
    return 0;
}


