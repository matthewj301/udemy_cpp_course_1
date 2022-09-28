#include <iostream>
#include <vector>
using namespace std;

// Pointer tests
int main() {
    int *int_ptr {nullptr};
    int_ptr = new int;
    cout << "Value of int_ptr is: " << int_ptr << endl;
    cout << "Value of what int_ptr points to is: " << *int_ptr << endl;
    cout << "Size of int_ptr is: " << sizeof(int_ptr) << endl;
    *int_ptr = 8;
    cout << "Value of what int_ptr points to is now: " << *int_ptr << endl;
    cout << "Addr of int_ptr is: " << &int_ptr << endl << endl;
    delete int_ptr;

    int *array_ptr {nullptr};
    int size {};
    cout << "Value of array_ptr is: " << array_ptr << endl;
    cout << "Size of array_ptr is: " << sizeof(array_ptr) << endl;
    cout << "How many ints do you want to store in the array? ";
    cin >> size;
    array_ptr = new int[size];
    cout << "Value of array_ptr is: " << array_ptr << endl;
    cout << "Size of array_ptr is: " << sizeof(array_ptr) << endl;
    delete [] array_ptr;

    return 0;
}

