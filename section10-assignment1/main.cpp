// Section 10
// Challenge - 
// Substitution Cipher

/*
Letter Pyramid!
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string user_input{};
    cout << "Enter a string to create a pyramid: ";
    cin >> user_input;
    string pyramid{""};
    string space (user_input.length() - 1, ' ');
    for (size_t _inc_index{0}; _inc_index < user_input.length(); _inc_index++) {
        pyramid = user_input.substr(0, _inc_index+1 );
        cout << space << pyramid;
        for (auto _desc_index {pyramid.length() - 1}; _desc_index > 0; --_desc_index) {
            cout << pyramid.at(_desc_index-1);   // don't go out of bounds
        }
        space.erase(0, 1);
        cout << endl;
    }

    cout << endl;
    return 0;
}

