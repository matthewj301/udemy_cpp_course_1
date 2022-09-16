#include <iostream>

// using namespace std; - Entire namespace, not ideal in terms of clutter/efficiency
using std::cout; // This is better, just namespace the methods you need
using std::cin;
using std::endl;


int main() {
    int favorite_number;
    int prompt = true;
    while (prompt) {
        cout << "Enter your favorite number between 1 and 100: ";
        cin >> favorite_number;
        if (favorite_number > 100) {
            cout << "whoops, that number is a bit too high, please try again..." << endl;
        } else {
            cout << "Whoa, " << favorite_number << " is my favorite number too!" << endl;
            prompt = false;
        }
    }
    return 0;
}
