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
    while (std::getline(response_file, line)) {
        if (line_count % 2 == 0) {
            int score{0};
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == answer_key[i]) {
                    score++;
                }
            }
            std::cout << score << endl;
        }  else {
            std::cout << line << endl;
        }
        line_count ++;
    }
    return 0;
}

