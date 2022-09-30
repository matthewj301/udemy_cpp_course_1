#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Returning pointers from functions

int *create_array(size_t, int initial_value=0);
void print_array(const int *, size_t);

int main() {
    int array_size {12};
    int *new_array;
    new_array = create_array(array_size);

    cout << "First array int mem addr: " << new_array << endl;
    cout << new_array[0] << endl;
    print_array(new_array, array_size);

    cout << "NOTICE - since memory was dynamically allocated (on the heap), it needs to be released after use!";
    delete [] new_array;
    return 0;
}

int *create_array(size_t size, int initial_value) {
    int *new_storage {nullptr};
    new_storage = new int[size];
    for (size_t i {0}; i < size; i++) {
        new_storage[i] = initial_value;
    }
    return new_storage;
}

void print_array(const int *const array, size_t size) {
    for (size_t i {0}; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}