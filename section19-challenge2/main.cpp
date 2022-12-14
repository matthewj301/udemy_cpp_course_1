// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>

using namespace std;
void print_header();
void print_footer(double average);
void print_student(const std::string &student, int score);
int process_response(const std::string &response, const std::string &answer_key);

void print_header() {
    std::cout << std::setw(15) << std::left << "Student"
              << std::setw(5) << "Score" << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
}

void print_footer(double average) {
    std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(15) << std::left << "Average score"
              << std::setw(5) << std::right << average;
}

void print_student(const std::string &student, int score) {
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << std::setw(15) << std::left << student
              << std::setw(5) << std::right << score << std::endl;
}

// return the number of correct responses
int process_response(const std::string &response, const std::string &answer_key) {
    int score {0};
    for (size_t i = 0; i < answer_key.size() ; ++i) {
        if (response.at(i)  == answer_key.at(i))
            score++;
    }
    return score;
}
int main() {
    std::ifstream response_file;
    std::string answer_key{};
    std::string s_name {};
    std::string s_response {};
    int running_sum {0};
    int total_students {0};
    double avg_score {0.0};

    response_file.open("../section19-challenge2/responses.txt");
    if (!response_file) {
        std::cerr << "File not opened, exiting...";
        return 1;
    }
    response_file >> answer_key;

    print_header();

    while (response_file >> s_name >> s_response) {
        ++total_students;
        int score = process_response(s_response, answer_key);
        running_sum += score;
        print_student(s_name, score);
    }

    if (total_students != 0)
        avg_score = static_cast<double>(running_sum)/total_students;

    print_footer(avg_score);

    response_file.close();
    std::cout << std::endl << std::endl;
    return 0;
}

