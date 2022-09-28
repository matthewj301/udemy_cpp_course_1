#include <iostream>
#include <vector>
using namespace std;

// Relation between pointers and arrays
int main() {
    int scores[] {100, 95, 89};
    int *score_ptr {scores}; //No need to use {&scores} because scores is already a pointer
    cout << scores << endl; // 100
    cout << score_ptr << endl; // 100
    cout << "NOTICE scores address (" << scores << ") and score_ptr address (" << score_ptr << ") are the same"<< endl;
    cout << "This is because arrays are just pointers to the first element of the array" << endl;
    cout << "So, we can access elements of the array the same way between arrays and pointers to arrays" << endl;
    cout << "scores[1] = " << scores[1] << endl;
    cout << "score_ptr[1] = " << score_ptr[1] << endl;
    cout << "scores[2] = " << scores[2] << endl;
    cout << "score_ptr[2] = " << score_ptr[2] << endl;
    cout << "scores[3] = " << scores[3] << endl;
    cout << "score_ptr[3] = " << score_ptr[3] << endl;

    cout << "We can also use pointer arithmetic to access the other elements of the array" << endl;
    cout << "*(scores + 1) = " << *(scores + 1) << endl;
    cout << "*(score_ptr + 1) = " << *(score_ptr + 1) << endl;
    cout << "*(scores + 2) = " << *(scores + 2) << endl;
    cout << "*(score_ptr + 2) = " << *(score_ptr + 2) << endl;
    cout << "*(scores + 3) = " << *(scores + 3) << endl;
    cout << "*(score_ptr + 3) = " << *(score_ptr + 3) << endl;

    cout << "NOTICE that when we add 1 to the pointer, we are adding 4 bytes to the pointer" << endl;
    cout << "This is because the pointer is a 4 byte integer" << endl;
    cout << "So, we are adding 4 bytes to the pointer to get the next element of the array" << endl;
    cout << (score_ptr) << endl;
    cout << (score_ptr + 1) << endl;
    cout << (score_ptr + 2) << endl;

    cout << *(score_ptr) << endl;
    cout << *(score_ptr + 1) << endl;
    cout << *(score_ptr + 2) << endl;

    cout << "NOTICE: you can use subscript notation or offset notation to access elements of the array and pointers" << endl;
    cout << "scores[0] is the same as *scores" << endl;
    cout << "scores[1] is the same as *(scores + 1)" << endl;
    cout << "scores[2] is the same as *(scores + 2)" << endl;

    cout << "score_ptr[0] is the same as *score_ptr" << endl;
    cout << "score_ptr[1] is the same as *(score_ptr + 1)" << endl;
    cout << "score_ptr[2] is the same as *(score_ptr + 2)" << endl;
    return 0;
}

