//
// Created by Matthew Johnson on 10/26/22.
//
#include <iostream>
#include <vector>

enum class ApplicationState {
    Unknown, Crashed, Ok
};

int main() {
    std::vector<ApplicationState> states{ApplicationState::Crashed, ApplicationState::Ok, ApplicationState::Unknown, ApplicationState::Ok, ApplicationState::Crashed, ApplicationState::Ok};

    for (auto state: states) {
        switch (state) {
            case ApplicationState::Crashed:
                std::cout << "App crashed!" << std::endl;
                break;
            case ApplicationState::Ok:
                std::cout << "App Ok" << std::endl;
                break;
            default:
                std::cout << "Unknown state!" << std::endl;
                break;
        }
    }

    return 0;
};