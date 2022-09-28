#include <iostream>
#include <vector>
using namespace std;

// Pointer tests
int main() {
    int num {10};
    cout << "Value of num is: " << num << endl;
    cout << "Size of num is: " << sizeof(num) << endl;
    cout << "Addr of num is: " << &num << endl << endl;

    int *pointer;
    cout << "We initialized a pointer without a value, so it's a garbage addr: " << num << endl;
    cout << "Garbage value of pointer is: " << pointer << endl;
    cout << "Size of pointer is: " << sizeof(pointer) << endl;
    cout << "Addr of pointer is: " << &pointer << endl << endl;
    pointer = nullptr;
    cout << "Value of pointer after nullptr is: " << pointer << endl;
    cout << "Size of pointer after nullptr is: " << sizeof(pointer) << endl;
    cout << "Addr of pointer after nullptr is: " << &pointer << endl << endl;

    int *b_p {nullptr};
    cout << "We just initialized a pointer (b_p) correctly with nullptr, so we don't have initial garbage mem addr: " << b_p << endl;
    cout << "Size of b_p is: " << sizeof(b_p) << endl;
    cout << "Addr of b_p is: " << &b_p << endl << endl;


    // Time to dereference and find what values a pointer points at

    int score {100};
    int *score_ptr {&score};
    cout << "Value of score is: " << score << endl;
    cout << "Addr of score is: " << &score << endl;
    cout << "Value of score_ptr is: " << score_ptr << endl;
    cout << "Addr of score_ptr is: " << &score_ptr << endl << endl;

    cout << "NOTICE how the value of score_ptr (" << score_ptr << ") is the same as the addr of score (" << &score << ")" << endl << endl;

    cout << "Dereferenced value of score_ptr (value of what it points to): " << *score_ptr << endl << endl;

    cout << "NOTICE how the dereferenced value of score_ptr (" << *score_ptr << ") is the same as the value of score (" << score << ")" << endl << endl;

    *score_ptr = 200;
    cout << "We changed the dereferenced value of score_ptr (the variable 'score') to 200" << endl;
    cout << "Value of score is now: " << score << endl;
    cout << "NOTICE how the dereferenced value of score_ptr (" << *score_ptr << ") is the same as the value of score (" << score << ")" << endl << endl;

    vector<string> people {"Matthew", "Mark", "Luke", "John"};
    vector<string> *vector_ptr {nullptr};

    cout << "Value of vector_ptr is: " << vector_ptr << endl;

    cout << "First person in people is: " << people.at(0) << endl;
    cout << "Addr of people is: " << &people << endl << endl;

    cout << "Now assigning vector_ptr to the addr of people" << endl;
    vector_ptr = &people;
    cout << "Value of vector_ptr is now: " << vector_ptr << endl;
    cout << "NOTICE how the value of vector_ptr (" << vector_ptr << ") is the same as the addr of people (" << &people << ")" << endl << endl;
    cout << "First dereferenced value of vector_ptr is: " << (*vector_ptr).at(0) << endl << endl; // Notice 2 different ways to dereference a vector pointer
    cout << "First dereferenced value of vector_ptr is: " << vector_ptr->at(0) << endl << endl << endl; // Notice 2 different ways to dereference a vector pointer

    cout << "Lets change the first person in people to 'Bobby' via the vector_ptr" << endl;
    vector_ptr->at(0) = "Bobby";
    cout << "First person in people is now: " << people.at(0) << endl << endl;

    cout << "Lets iterate through the vector_ptr and print out all the names" << endl;
    for (auto person: *vector_ptr) {
        cout << person << endl;
    }
    cout << "Lets iterate through the vector_ptr and assign new names" << endl << endl;
    for (auto person: *vector_ptr) {
        person = "No Name";
    }
    cout << "Lets iterate through the vector_ptr and print out all the names again" << endl;
    for (auto person: *vector_ptr) {
        cout << person << endl;
    }
    cout << "Nothing changed! Why? Because we didn't change the actual vector, we just changed the copy of the vector that we made in the for loop" << endl << endl;
    return 0;
}

