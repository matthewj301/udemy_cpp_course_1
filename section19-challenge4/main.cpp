// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>

using namespace std;

bool open_read_file(ifstream &, string &);

bool open_write_file(ofstream &, string &);

bool copy_file(string &, string &);

int main() {
    string in_path{"../section19-challenge4/romeoandjuliet"};
    string out_path{"../section19-challenge4/romeoandjuliet_numbered.txt"};
    bool copy_return = copy_file(in_path, out_path);
    if (copy_return) {
        cout << "Successfully copied " << in_path << "." << endl;
        return 0;
    } else {
        cout << "Could not copy file..." << endl;
        return 1;
    }
}

bool open_read_file(ifstream &read_obj, string &read_filepath) {
    read_obj.open(read_filepath);
    if (read_obj.is_open()) {
        return true;
    }
    cout << "Could not open read file " << read_filepath << endl;
    return false;
}

bool open_write_file(ofstream &write_obj, string &write_filepath) {
    write_obj.open(write_filepath, ios::app);
    if (write_obj.is_open()) {
        return true;
    }
    cout << "Could not open write file " << write_filepath << endl;
    return false;
}

bool copy_file(string &read_filepath, string &destination_filepath) {
    ifstream in_file;
    ofstream out_file;

    if (!open_read_file(in_file, read_filepath)) {
        return false;
    }
    if (!open_write_file(out_file, destination_filepath)) {
        return false;
    }
    size_t line_number{1};
    string line{};
    bool start_numbering{false};

    while (getline(in_file, line)) {
        string formatted_line_num{to_string(line_number) + ": "};
        if (start_numbering) {
            out_file << setw(6) << formatted_line_num << line << endl;
        } else {
            if (line_number < 4) {
                out_file << setw(15) << line << endl;
            } else {
                line_number = 1;
                out_file << setw(6) << to_string(line_number) + ": " << line << endl;
                start_numbering = true;
            }
        }
        line_number++;
    }
    in_file.close();
    out_file.close();
    return true;
}
