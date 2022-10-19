// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include "exception"
#include <boost/algorithm/string.hpp>
#include <ctype.h>

using namespace std;

ifstream open_file(string &);
void convert_word_to_lowercase(string &);
void clean_word(string &);
bool find_substring(const string &, const string &);
void search_text_for_substring(string &, string &);

int main() {
    string file_path {"../section19-challenge3/romeoandjuliet.txt"};

    string lookup_substring {};
    cout << "Enter a substring to search: ";
    cin >> lookup_substring;
    convert_word_to_lowercase(lookup_substring);
    search_text_for_substring(file_path, lookup_substring);

    
    cout << endl;
    return 0;
}

ifstream open_file(string &file_path) {
    ifstream in_file;
    in_file.open(file_path);
    if (!in_file) {
        cerr << "Could not open file, exiting..." << endl;
        throw exception();
    }
    return in_file;
}

void convert_word_to_lowercase(string &word) {
    boost::algorithm::to_lower(word);
}

void clean_word(string &word) {
    auto it = std::remove_if(word.begin(), word.end(), [](char const &c) {
        return !std::isalnum(c);
    });

    word.erase(it, word.end());
    boost::algorithm::trim(word);
}

bool find_substring(const string &target, const string &word_to_find) {
    size_t substring_len = word_to_find.length();
    if (target.length() >= substring_len) {
        size_t found = target.find(word_to_find);
        if (found == string::npos) {
            return false;
        }
        return true;
    }
    return false;
}

void search_text_for_substring(string &file_path, string &substring) {
    int total_words_searched {0};
    int found_words {0};
    ifstream text = open_file(file_path);
    string word {};
    while (text >> word) {
        total_words_searched++;
        convert_word_to_lowercase(word);
        clean_word(word);
        bool search_result = find_substring(word, substring);
        if (search_result) {
            found_words++;
        }
    }
    cout << "Total words searched: " << total_words_searched << endl;
    cout << "Number of instances of " << substring << " found: " << found_words << endl;
}

