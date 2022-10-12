#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment

    bool operator==(const Mystring &) const;
    bool operator!=(const Mystring &) const;

    bool operator<(const Mystring &) const;
    bool operator>(const Mystring &) const;

    Mystring operator-() const; // make lowercase
    Mystring operator+(const Mystring &) const; // concatenate

    Mystring &operator+=(const Mystring &); // concatenate and assign

    Mystring operator*(const int &) const; // repeat string n times
    Mystring &operator*=(const int &); // repeat string n times and assign

    Mystring &operator++(); // to Uppercase
    Mystring operator++(const int); // to Uppercase

    
    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_