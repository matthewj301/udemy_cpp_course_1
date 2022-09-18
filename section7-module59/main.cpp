#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector <int> vec {10,20,30,40,50};
    cout << vec.at(0) << " " << vec.at(4) << endl;
    vec[0] = 100;
    vec[4] = 1000;
    cout << vec.at(0) << " " << vec.at(4) << endl;


    return 0;
}

