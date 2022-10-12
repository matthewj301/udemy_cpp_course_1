#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

bool Mystring::operator==(const Mystring &rhs) const {
    return (strcmp(str, rhs.str) == 0);
}
bool Mystring::operator!=(const Mystring &rhs) const {
    return (strcmp(str, rhs.str) != 0);
}

bool Mystring::operator<(const Mystring &rhs) const {
    return (str < rhs.str);
}

bool Mystring::operator>(const Mystring &rhs) const {
    return (str > rhs.str);
}

Mystring Mystring::operator-() const {
    char *buff = new char[strlen(str) + 1];
    for (size_t i=0; i<strlen(str); i++){
        buff[i] = tolower(str[i]);
    }
    Mystring tmp {buff};
    delete [] buff;
    return tmp;
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);
    Mystring tmp {buff};
    delete [] buff;
    return tmp;
}

Mystring &Mystring::operator+=(const Mystring &rhs) {
    char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);
    delete [] str;
    str = buff;
    buff = nullptr;
    return *this;
}

Mystring Mystring::operator*(const int &rhs) const {
    char *buff = new char[(strlen(str) * rhs) + 1];
    strcpy(buff, str);
    for (int mult=1; mult<rhs; mult++){
        strcat(buff, str);
    }
    Mystring tmp {buff};
    delete [] buff;
    return tmp;
}

Mystring &Mystring::operator*=(const int &rhs) {
    char *buff = new char[(strlen(str) * rhs) + 1];
    strcpy(buff, str);
    for (int mult=1; mult<rhs; mult++) {
        strcat(buff, str);
    }
    delete [] str;
    str = buff;
    buff = nullptr;
    return *this;
}

Mystring &Mystring::operator++() {
    for (size_t i=0; i<strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
    return *this;
}
Mystring Mystring::operator++(const int x) {
    Mystring tmp {*this};
    operator++();
    return tmp;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

