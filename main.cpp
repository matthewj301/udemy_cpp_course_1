#include <iostream>

int main() {
    int favorite_number;
    int prompt = true;
    while (prompt) {
        std::cout << "Enter your favorite number between 1 and 100: ";
        std::cin >> favorite_number;
        if (favorite_number > 100) {
            std::cout << "whoops, that number is a bit too high, please try again..." << std::endl;
        } else {
            std::cout << "Whoa, " << favorite_number << " is my favorite number too!" << std::endl;
            prompt = false;
        }
    }
    return 0;
}
