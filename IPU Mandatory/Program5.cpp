/*  PROBLEM STATEMENT: Implement a string class containing following functions:
      1.	overload + operator to carry out concatenation of strings
      2.	overload = operator to carry out string copy
      3.	overload <= operator to carry out the comparison of strings
      4.	function to display length of a string
      5.	function toLower() to convert uppercase letters to lowercase
      6.	function toUpper() to convert lowercase letters to uppercase */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cctype>
using namespace std;

class Mystring {
    char* str;

public:
    Mystring(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    ~Mystring() {
        delete[] str;
    }

    Mystring operator+(const Mystring& op2) const {
        Mystring temp("");
        delete[] temp.str;

        temp.str = new char[strlen(str) + strlen(op2.str) + 1];
        strcpy(temp.str, str);
        strcat(temp.str, "");
        strcat(temp.str, op2.str);

        return temp;
    }

    Mystring& operator=(const Mystring& right) {
        if (this != &right) {
            delete[] str;
            str = new char[strlen(right.str) + 1];
            strcpy(str, right.str);
        }
        return *this;
    }

    bool operator<=(const Mystring& right) const {
        return strcmp(str, right.str) <= 0;
    }

    int length() const {
        return strlen(str);
    }

    void toLower() {
        for (int i = 0; str[i] != 0; i++) {
            str[i] = tolower((unsigned char)str[i]);
        }
    }

    void toUpper() const {
        for (int i = 0; str[i] != 0; i++) {
            str[i] = toupper((unsigned char)str[i]);
        }
    }

    void show() const {
        cout << str << endl;
    }
};

int main() {
    Mystring s2("PINE");
    Mystring s3("apple");

    Mystring s4 = s2 + s3;
    cout << "Concatenated string is: ";
    s4.show();

    Mystring s5(" ");
    s5 = s2;
    cout << "Copied string is: ";
    s5.show();

    if (s2 <= s3) {
        cout << "String 2 is less than or equal to string 1" << endl;
    }
    else {
        cout << "String 2 is more than string 1" << endl;
    }

    cout << "The length of string 1 is: " << s2.length() << endl;

    s2.toLower();
    cout << "Lowercase of first string is: ";
    s2.show();

    s3.toUpper();
    cout << "Uppercase of second string is: ";
    s3.show();

    return 0;
}
