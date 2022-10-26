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
#include <functional>
#include <numeric>

using namespace std;

class Person {
    friend ostream &operator<<(ostream &os, const Person &rhs);

private:
    string name;
    int age;
public:
    Person() = default;

    Person(string name, int age)
            : name{name}, age{age} {}

    Person(const Person &p) = default;

    string get_name() const {
        return name;
    }

    void set_name(string new_name) {
        this->name = std::move(new_name);
    }

    int get_age() const {
        return age;
    }

    void set_age(int new_age) {
        this->age = new_age;
    }

    // STATEFUL LAMBDAS
    auto change_person() {
        return [this](string &&new_name, int &&new_age) {
            name = new_name;
            age = new_age;
        };
    }
};

ostream &operator<<(ostream &os, const Person &rhs) {
    os << "[Person: " << rhs.name << ": " << rhs.age << "]";
    return os;
}

class Multiplier {
private:
    int num{};
public:
    // constructor
    explicit Multiplier(int n)
            : num{n} {}

    int get_num() const {
        return num;
    }

    // function object
    int operator()(int n) const {
        return n * num;
    }
};

class Password_Validator1 {
private:
    char restricted_sym {'$'};
public:
    bool is_valid(std::string password) {
        return std::all_of(password.begin(), password.end(), [this] (char character)
        {
            return character != restricted_sym;
        });
    }
};

class Password_Validator2 {
private:
    std::vector<char> restricted_syms {'!','$','%'};
public:
    bool is_valid(std::string password) {
        return std::all_of(password.begin(), password.end(), [this] (char character)
        {
            return std::none_of(restricted_syms.begin(), restricted_syms.end(), [character] (char symbol)
            {
                return character == symbol;
            });
        });
    }
};

// Return lambda from function
auto add_another_int_bonus() {
    return [](vector<int> &scores, int bonus) {
        for (auto &score: scores) {
            score += bonus;
        }
    };
}

// pass lambda in order to change function functionality
void print_if(const vector<int> &nums, bool (*predicate)(int)) {
    for (auto i: nums) {
        if (predicate(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Pass a lambda function as a parameter
void add_int_bonus(void (*lam)(vector<int> &, int), vector<int> &scores, int bonus) {
    lam(scores, bonus);
}

void lambda_tests1() {
    Multiplier multi{25};

    // LAMBDA FUNCTIONS ASSIGNED TO VARIABLES
    auto display = [](auto vec) {
        for (auto v: vec) {
            cout << v << " ";
        }
        cout << endl;
    };
    auto bonus = [](auto &scores, auto bonus_points) {
        for (auto &score: scores) {
            score += bonus_points;
        }
    };

    // LAMBDA AS FUNCTION PARAM
    vector<int> numbers{1, 2, 3, 4};
    display(numbers);
    add_int_bonus(bonus, numbers, 10);
    display(numbers);
    cout << endl;

    // LAMBDA AS FUNCTION RETURN
    // NOTE: when returning lambda from function, assign to var first, then pass lambda params to the assigned var
    auto return_lambda = add_another_int_bonus();
    return_lambda(numbers, 100);
    display(numbers);
    cout << endl;

    // FUNCTION OBJECT
    // Utilizing function object to multiply by each num in vector, std::transform sets result back in vector
    transform(numbers.begin(), numbers.end(), numbers.begin(), multi);
    display(numbers);
    cout << endl;

    // RAW LAMBDA IN TRANSFORM - DOES THE SAME THING AS THE ABOVE FUNCTION OBJECT
    vector<int> numbers2{1, 2, 3, 4};
    display(numbers2);
    transform(numbers2.begin(), numbers2.end(), numbers2.begin(), [&](int x) { return x * multi.get_num(); });
    display(numbers2);
    cout << endl;

    // DISPLAY ACCEPTS INTS OR BOOLS BY UTILIZING AUTO
    vector<int> scores1{93, 81, 73, 65, 91, 77};
    vector<double> scores2{93.4, 81.1, 73.9, 65.3, 91.8, 77.5};
    display(scores1);
    display(scores2);
    cout << endl;

    // LAMBDA AS ASSIGNED VARIABLE - NOTE WE CAN USE AUTO TO OVERLOAD!
    bonus(scores1, 10);
    bonus(scores2, 12.3);
    display(scores1);
    display(scores2);
    cout << endl;

    // LAMBDA PASSED TO FUNCTION IN ORDER TO CHANGE FUNCTIONALITY
    vector<int> numbers3{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // HERE, ONLY PRINT IF EVEN
    print_if(numbers3, [](auto x) { return x % 2 == 0; });
    // HERE, ONLY PRINT IF ODD
    print_if(numbers3, [](auto x) { return x % 2 != 0; });
    // HERE, ONLY PRINT IF > 3
    print_if(numbers3, [](auto x) { return x > 3; });

    // STATEFUL LAMBDAS
    Person person1{"Matthew", 27};
    cout << person1 << endl;

    auto change_person1 = person1.change_person();
    change_person1("Katie", 30);
    cout << person1 << endl;
}

// section20 module 274
void test1() {
    std::cout << "\n------------------ Test 1 ------------------" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5};

    std::for_each(vec.begin(), vec.end(), [](int num) {
        std::cout << num << std::endl;
    });
}

void test2() {
    std::cout << "\n\n------------------ Test 2 ------------------" << std::endl;
    struct Point {
        int x;
        int y;
    };

    Point pt1{1, 2};
    Point pt2{4, 3};
    Point pt3{3, 5};
    Point pt4{5, 1};

    std::vector<Point> triangle1{pt1, pt2, pt3};
    std::vector<Point> triangle2{pt2, pt3, pt1};
    std::vector<Point> triangle3{pt1, pt2, pt4};

    if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle2.begin(), [](Point lhs, Point rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    })
            )
        std::cout << "Triangle 1 nad Triangle 2 are equivalent" << std::endl;
    else
        std::cout << "Triangle 1 nad Triangle 2 are not equivalent" << std::endl;

    if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle3.begin(), [](Point lhs, Point rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    })
            )
        std::cout << "Triangle 1 nad Triangle 3 are equivalent" << std::endl;
    else
        std::cout << "Triangle 1 nad Triangle 3 are not equivalent" << std::endl;
}

void test3() {
    std::cout << "\n\n------------------ Test 3 ------------------" << std::endl;
    std::vector<int> test_scores{100, 98, 89, 67, 79, 85, 91, 94, 100, 83};
    int bonus_points{10};

    std::cout << "Scores before bonus assignment" << std::endl;
    for (auto score: test_scores) {
        std::cout << score << " ";
    }

    std::transform(test_scores.begin(), test_scores.end(), test_scores.begin(), [bonus_points](int score) {
        return score += bonus_points;
    });

    std::cout << "Scores after bonus assignment" << std::endl;
    for (auto score: test_scores) {
        std::cout << score << " ";
    }
}

void test4() {
    std::cout << "\n\n------------------ Test 4 ------------------" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Vec before remove_if: " << std::endl;
    for (auto num: vec) {
        std::cout << num << " ";

    }
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) {
                  return x % 2 == 0;
              }),
              vec.end());

    std::cout << "Vec after remove_if: " << std::endl;
    for (auto num: vec) {
        std::cout << num << " ";

    }
}

void test5() {
    std::cout << "\n\n------------------ Test 5 ------------------" << std::endl;
    Person person1{"Matthew", 27};
    Person person2{"Katie", 30};
    Person person3{"Fred", 28};
    Person person4{"Bob", 40};
    Person person5{"Joe", 18};

    std::vector<Person> persons{person1, person2, person3, person4,  person5};

    std::cout << "\nperson vec before sorting: " << std::endl;
    for (auto &person: persons) {
        std::cout << person << " ";
    }

    std::sort(persons.begin(), persons.end(), [](Person lhs, Person rhs) {
        return lhs.get_age() < rhs.get_age();
    });

    std::cout << "\n\nperson vec after sorting: " << std::endl;
    for (auto &person: persons) {
        std::cout << person << " ";
    }
}

bool in_between(const std::vector<int> &nums, int start_val, int end_val) {
    bool result {false};
    auto between_lambda = [start_val, end_val](int val) {
        return val >= start_val && val <= end_val;
    };
    result = std::all_of(nums.begin(), nums.end(), between_lambda);
    return result;
}

void test6(){
    std::vector<int> numbers {5,6,7,8,9,10,11,12,13,14,15};
    std::cout << std::boolalpha;
    std::cout << in_between(numbers, 7, 13) << endl;
    std::cout << in_between(numbers, 3, 20) << endl;
}

void test7() {
    std::string pw1 {"asdns%dfln13"};
    std::string  pw2 {"adasasd"};
    std::string  pw3 {"adas!as$d"};

    Password_Validator1 validator1 {};
    std::cout << std::boolalpha;
    std::cout << validator1.is_valid(pw1) << std::endl;
    std::cout << validator1.is_valid(pw2) << std::endl;
    std::cout << validator1.is_valid(pw3) << std::endl;

    Password_Validator2 validator2 {};
    std::cout << validator2.is_valid(pw1) << std::endl;
    std::cout << validator2.is_valid(pw2) << std::endl;
    std::cout << validator2.is_valid(pw3) << std::endl;

}

void generated_test() {
    std::cout << "\n\n------------------ Test 3 ------------------" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5};

    int total = std::accumulate(vec.begin(), vec.end(), 0, [](int total, int num) {
        return total + num;
    });

    std::cout << "Total: " << total << std::endl;
}

int main() {
    test7();

    return 0;
}