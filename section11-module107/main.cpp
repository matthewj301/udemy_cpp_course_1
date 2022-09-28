// Section 11
// Function Prototypes
// Area of Circle and Volume of a Cylinder
#include <iostream>
#include <vector>

using namespace std;

void print(int);
void print(double);
void print(string);
void print(vector<string>);

int main() {
    print(100);
    print(123.5);
    print("Hello");
    print("C-style string");
    vector<string> stooges {"Larry", "Moe", "Curly"};
    print(stooges);
    return 0;

}

void print(int num) {
    cout << "Printing int: " << num << endl;
}
void print(double num) {
    cout << "Printing double: " << num << endl;
}
void print(string str) {
    cout << "Printing string: " << str << endl;
}
void print(vector<string> v) {
    cout << "Printing vector: ";
    for (auto i: v) {
        cout << i << " ";
    }
    cout << endl;
}