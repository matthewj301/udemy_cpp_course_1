#include <iostream>
#include <vector>
#include <string>
using namespace std;

// References

void print_vector(vector<string> &);
void update_vector_without_effect(vector<string>, string &);
void update_vector(vector<string> &, string &);
void simple_ref_example();

int main() {
    vector<string> people {"Matthew", "Fred", "Bobby"};
    string update_word = "Katie";

    print_vector(people);
    update_vector_without_effect(people, update_word);
    print_vector(people);
    update_vector(people, update_word);
    print_vector(people);
    simple_ref_example();

    return 0;
}

void simple_ref_example() {
    int num{100};
    int &ref_num{num};

    cout << "num integer: " << num << endl;
    cout << "ref_num reference: " << ref_num << endl << endl;

    cout << "Assigning 200 to num..." << endl;
    num = 200;
    cout << "num integer: " << num << endl;
    cout << "ref_num reference: " << ref_num << endl << endl;
    cout << "Notice ref_num was also implicitly updated when num was set to 200." << endl << endl;

    cout << "Assigning 300 to ref_num..." << endl;
    ref_num = 300;
    cout << "num integer: " << num << endl;
    cout << "ref_num reference: " << ref_num << endl << endl;
    cout << "Notice num was also implicitly updated when ref_num was set to 300." << endl <<endl;
}

void print_vector(vector<string> & str_vector) {
    for (auto const &vect: str_vector) {
        cout << vect << " ";
    }
    cout << endl;
}

void update_vector_without_effect(vector<string> str_vector, string & update_str) {
    for (auto vect: str_vector) {
        vect = update_str;
    }
}

void update_vector(vector<string> & str_vector, string & update_str) {
    for (auto &vect: str_vector) {
        vect = update_str;
    }
}