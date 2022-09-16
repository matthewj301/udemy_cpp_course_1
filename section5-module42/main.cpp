#include <iostream>

// using namespace std; - Entire namespace, not ideal in terms of clutter/efficiency
using std::cout; // This is better, just namespace the methods you need
using std::cin;
using std::endl;

int test {18}; // Global variable

int main() {
    cout << "Global variable test: " << test << endl;
    int test {10}; // Local variable
    cout << "Local variable override test: " << test << endl;

    cout << "Hello, World!" << endl;
    cout << "Hello World!";
    cout << "Hello World!\n";
    cout << "Hello World!\n" << endl;
    cout << "Hello World!\n";

    char name = 'A';
    cout << "hello " << name << endl;
    int num1;
    int num2;
    cout << "1. Enter 2 numbers (2nd will be discarded!): ";
    cin >> num1;
    cin >> num2;
    cout << "1. You entered: " << num1 << "\n" << endl;
    
    cout << "2. Enter 2 numbers (we will keep both): ";
    cin >> num2 >> num1;
    cout << "2. You entered: " << num2 << " and " << num1 << "\n" << endl;
    
    cout << "4. Enter 2 numbers (2nd will grabbed later): ";
    cin >> num1;
    cout << "4. You entered: " << num1;
    cin >> num2;
    cout << "4. and after grabbing from stream " << num2 << endl;

    return 0;
}
