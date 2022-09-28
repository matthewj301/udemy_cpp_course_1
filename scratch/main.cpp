#include <iostream>
using namespace std;

// Pointer tests
int main() {
    int num {10};
    int *pointer;
    cout << "Value of num is: " << num << endl;
    cout << "Size of num is: " << sizeof(num) << endl;
    cout << "Addr of num is: " << &num << endl << endl;
    cout << "Garbage value of pointer is: " << pointer << endl;
    cout << "Size of pointer is: " << sizeof(pointer) << endl;
    cout << "Addr of pointer is: " << &pointer << endl << endl;
    pointer = nullptr;
    cout << "Value of pointer after nullptr is: " << pointer << endl;
    cout << "Size of pointer after nullptr is: " << sizeof(pointer) << endl;
    cout << "Addr of pointer after nullptr is: " << &pointer << endl << endl;
    return 0;
}

