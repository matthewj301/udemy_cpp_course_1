// Section 11
// passing arrays to functions
#include <iostream>
#include <vector>

using namespace std;

void print_array(const int [], size_t size);
void zero_array(int [], size_t size);

int main() {
    int my_numbers[] {1, 2, 3, 4, 5};
    print_array(my_numbers, 5);
    zero_array(my_numbers, 5);
    print_array(my_numbers, 5);
    return 0;

}

void print_array(const int numbers [], size_t size) {
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << endl;
    }
}

void zero_array (int numbers [], size_t size) {
    for (int i = 0; i < size; i++) {
        numbers[i] = 0;
    }
}