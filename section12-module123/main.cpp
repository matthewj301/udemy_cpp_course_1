#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Pointer arithmetic
int main() {
    string name_1 = "matthew";
    string name_2 = "mark";
    string name_3 = "bobby";
    string name_4 = "matthew";

    string *p1 {&name_1};
    string *p2 {&name_2};
    string *p3 {&name_1};
    string *p4 {&name_4};

    // You can evaluate 2 pointers with relational operators
    // but keep in mind you are comparing the addresses, not the values
    cout << "Evaluating p1 (pointing at name_1) and p2 (pointing at name_2: " << (p1 == p2) << endl; // 0
    cout << "Evaluating p1 (pointing at name_1) and p2 (pointing at name_1): " << (p1 == p3) << endl; // 1
    cout << "Evaluating p1 (pointing at name_1) and p2 (pointing at name_4): " << (p1 == p4) << endl; // 0
    cout << "NOTICE: p1 and p4 are pointing at the same string value, but they evaluate to False " << endl;
    cout << "because they are pointing at 2 different memory addresses (aka - 2 different variables)" << endl;
    cout << "p1: " << p1 << endl;
    cout << "p4: " << p4 << endl;
    cout << "p1 points at: " << *p1 << endl;
    cout << "p4 points at: " << *p4 << endl;

    cout << "You can also use the dereference operator to get the address (variable value) of a pointer." << endl;
    cout << "We can use this to compare the values of 2 pointers, instead of the addresses" << endl;
    cout << "Evaluating the values of p1 and p4: " << (*p1 == *p4) << endl; // 1
    cout << "Evaluating the values of p1 and p2: " << (*p1 == *p2) << endl; // 0

    int scores [] {100, 95, 89, -1};
    // Using -1 as a sentinel value to indicate the end of the array
    int *score_ptr {scores};
    cout << "initial score_ptr addr: " << score_ptr << endl;
    cout << "initial score_ptr value: " << *score_ptr << endl;
    // score_ptr points to the first element in the array initially
    while (*score_ptr != -1) {
        // Dereference the pointer to get the value
        cout << *score_ptr << endl;
        // Increment the pointer to point to the next element in the array
        score_ptr++;
    }
    cout << "NOTICE you can do the above on 1 line: " << endl;
    score_ptr = scores;
    while (*score_ptr != -1) {
        cout << *(score_ptr++) << endl;
    }
    cout << "In the above, since * and ++ have different precedence, "
            "you can use parentheses to make it clear what you want to happen first " << endl;
    cout << "ie. *score_ptr++ is the same as *(score_ptr++)" << endl << endl;
    cout << "NOTICE how the pointer now points to the last value of the scores array" << endl;
    cout << "after-loop score_ptr addr: " << score_ptr << endl;
    cout << "after-loop score_ptr value: " << *score_ptr << endl;
    cout << "scores array -1 value addr: " << &scores[3] << endl;
    cout << "scores array -1 value: " << scores[3] << endl;
    cout << (scores == score_ptr) << endl; // This is now False
    cout << (&scores[3] == score_ptr) << endl; // This is now True
    return 0;
}

