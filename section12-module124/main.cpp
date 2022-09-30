#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Consts, Pointers, and Functions

void double_data(int *);
void print_array(int *, int);
void print_vector(const vector<string> *);

int main() {
    int high_score {100};
    int *high_score_ptr {nullptr};
    high_score_ptr = &high_score;
    cout << "Here, we pass in the mem address of the high_score variable directly using &" << endl;
    cout << "High score before ptr double: " << high_score << endl;
    double_data(&high_score);
    cout << "High score after ptr double: " << high_score << endl << endl;
    cout << "You can also pass in a pointer variable, instead of the mem address directly from the variable" << endl;
    cout << "High score before ptr double: " << high_score << endl;
    double_data(high_score_ptr);
    cout << "High score after ptr double: " << high_score << endl << endl;

    vector<string> people {"Matthew", "Bobby", "Fred"};
    print_vector(&people);

    int test_array [] {1,2,3,4,-1};
    print_array(test_array, -1);
    return 0;
}

void double_data(int *int_ptr) {
    *int_ptr *=2;
}

void print_vector(const vector<string> *const vector) {
    cout << "Your people are: ";
    for (auto vec: *vector) {
        cout << vec << " ";
    }
    cout << endl;
}

void print_array(int *array, int sentinel_val) {
    while (*array != sentinel_val) {
        // NOTE important to increment the array (basically just a pointer) or else it will loop on first value infinitely
        cout << *array++ << " ";
    }
}

