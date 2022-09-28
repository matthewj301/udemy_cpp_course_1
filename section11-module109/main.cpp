// Section 11
// passing by reference!
#include <iostream>
#include <vector>

using namespace std;

void scale_number(int &);
void swap_numbers(int &, int &);

int main() {
    int my_number_1 {10};
    int my_number_2 {40};
    cout << "my_number before: " << my_number_1 << endl;
    scale_number(my_number_1);
    cout << "my_number after: " << my_number_1 << endl;
    cout << "my_number_1 before swap: " << my_number_1 << endl;
    cout << "my_number_2 before swap: " << my_number_2 << endl;
    swap_numbers(my_number_1, my_number_2);
    cout << "my_number_1 after swap: " << my_number_1 << endl;
    cout << "my_number_2 after swap: " << my_number_2 << endl;
    return 0;

}

void scale_number(int &number) {
    if (number > 0) {
        number *= 2;
    }
}

void swap_numbers(int &num_1, int &num_2) {
    int temp = num_1;
    num_1 = num_2;
    num_2 = temp;
}