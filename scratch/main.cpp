// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

class Multiplier {
private:
    int num{};
public:
    // constructor
    explicit Multiplier(int n)
    : num{n}
    {}
    int get_num() const {
        return num;
    }

    // function object
    int operator()(int n) const {
        return n * num;
    }
};

int main() {
    vector<int> numbers {1,2,3,4};
    Multiplier multi {25};
    // Lambda functions
    auto display = [](auto vec) {
        for (auto v: vec) {
            cout << v << endl;
        }
    };
    auto bonus = [] (auto &scores, auto bonus_points) {
        for (auto &score: scores) {
            score += bonus_points;
        }
    };
    display(numbers);
    // Utilizing function object to multiply by each num in vector, std::transform sets result back in vector
    transform(numbers.begin(), numbers.end(), numbers.begin(), multi);
    display(numbers);

    vector<int> numbers2 {1,2,3,4};
    display(numbers2);
    transform(numbers2.begin(), numbers2.end(), numbers2.begin(), [&multi](int x) { return x * multi.get_num();});
    display(numbers2);

    vector<int> scores1 {93, 81, 73, 65, 91, 77};
    vector<double> scores2 {93.4, 81.1, 73.9, 65.3, 91.8, 77.5};
    display(scores1);
    display(scores2);

    bonus(scores1, 10);
    bonus( scores2, 12.3);
    display(scores1);
    display(scores2);

    return 0;
}