// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    string txt{"Hello"};
    string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
    cars[0] = "Opel";
    int x = 1;
    int y = 10;
    cout << max(x, y) << endl;
    txt.at(0) = 'j';
    cout << txt[0] << endl;
    double rounding = 2.6;
    cout << round(rounding) << endl;
    return 0;
}