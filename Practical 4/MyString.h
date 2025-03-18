#ifndef MY_STRING
#define MY_STRING

#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>

class MyString
{
    private:
        std::string mString;

    public:  
        std::string cleanString(std::string dirtystring);
        MyString(std::string instring);
        MyString();
        ~MyString();
        void print();
        std::string operator+(std:: string rhs);
        std::string operator+(const MyString& rhs);
        MyString& operator+=(const MyString& rhs);
        bool operator<(const MyString& rhs);
        bool operator>(const MyString& rhs);
        bool operator==(const MyString& rhs);
        bool operator!=(const MyString& rhs);
        MyString& operator=(std::string input);
        MyString& operator=(std::fstream& file);
        MyString& operator=(const MyString& rhs);
        void clear();
        bool operator!();
};


#endif