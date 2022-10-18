// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    std::ifstream response_file{"../section19-challenge2/responses.txt"};
    if (!response_file) {
        std::cout << "File not opened, exiting...";
        return 0;
    }
    std::string answer_key{};
    std::getline(response_file, answer_key);
    std::string line{};
    int line_count{1};
    int score {0};
    while (std::getline(response_file, line)) {
        if (line_count % 2 != 0) {
            score = 0;
            std::cout << line << endl;
        }  else {
            for (int i = 0; i < line.length(); i++) {
                std::cout << line << endl;
                std::cout << line.length() << endl;
                std::cout << answer_key << endl;
                if (line[i] == answer_key[i]) {
                    score = score + 1;
                }
            }
            std::cout << score << endl;
        }
        line_count++;
    }
    return 0;
}

