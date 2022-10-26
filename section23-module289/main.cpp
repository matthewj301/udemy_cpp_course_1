//
// Created by Matthew Johnson on 10/26/22.
//
#include <iostream>
#include <vector>

enum State {
    Unknown, Crashed, Ok
};

int main() {
    std::vector<State> states{Crashed, Ok, Unknown, Ok, Crashed, Ok};

    for (auto state: states) {
        switch (state) {
            case Crashed:
                std::cout << "App crashed!" << std::endl;
                break;
            case Ok:
                std::cout << "App Ok" << std::endl;
                break;
            default:
                std::cout << "Unknown state!" << std::endl;
                break;
        }
    }

    return 0;
};