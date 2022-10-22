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

template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b) {
    std::cout << a << " " << b << std::endl;
}

struct person {
    std::string name;
    int age;
    bool operator<(const person &rhs) const {
        return this->age < rhs.age;
    }
};

template <typename T>
class Item {
private:
    std::string name;
    T value;
public:
    Item(std::string name, T value)
    : name{std::move(name)}, value{value} {}
    std::string get_name() const {return name;}
    T get_value() const {return value;}
};

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    return false;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
                                           "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
                                           "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;

    std::cout << min<int>(2,3) << std::endl;
    std::cout << min<double>(2.3, 1.2) << std::endl;
    std::cout << min(50, 78) << std::endl;
    std::cout << min(23.43, 55.32) << std::endl;

    person matt {"matt", 27};
    person katie {"katie", 30};
    person sum = min(matt, katie);
    std::cout << sum.name << " is younger." << std::endl;

    func<std::string, std::string>("matt", "katie");

    Item<int> int_item {"integer", 1};
    Item<double> double_item {"double", 2.3};
    Item<std::string> str_item {"string", "string_val"};

    std::cout << int_item.get_name() << " " << int_item.get_value() << std::endl;
    std::cout << double_item.get_name() << " " << double_item.get_value() << std::endl;
    std::cout << str_item.get_name() << " " << str_item.get_value() << std::endl;

    return 0;
}