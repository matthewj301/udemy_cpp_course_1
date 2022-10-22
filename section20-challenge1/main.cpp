// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string &s) {
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<char> forward;
    std::deque<char> reverse;
    for (auto letter: s) {
        if (isalpha(letter)) {
            forward.push_back(tolower(letter));
            reverse.push_front(tolower(letter));
        }
    }
    if (forward == reverse) {
        return true;
    }
    return false;
}

bool is_another_palindrome(const std::string &s) {
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<char> reverse;
    for (auto letter: s) {
        if (isalpha(letter)) {
            reverse.push_front(std::tolower(letter));
        }
    }
    char f_char{};
    char b_char{};
    while (reverse.size() > 1) {
        f_char = reverse.front();
        b_char = reverse.back();
        if (f_char != b_char) {
            return false;
        }
        reverse.pop_front();
        reverse.pop_back();
    }
    return true;
}

int main() {
    std::vector<std::string> test_strings{"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
                                          "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
                                          "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
                                          "This is a palindrome", "palindrome"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto &s: test_strings) {
        // My solution
        std::cout << std::setw(8) << std::left << is_palindrome(s) << " " << s << std::endl;
        // Instructor solution
        std::cout << std::setw(8) << std::left << is_another_palindrome(s) << " " << s << std::endl;
        std::cout << std::endl;
    }
    return 0;
}