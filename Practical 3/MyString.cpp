#include "MyString.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>

MyString::MyString()
{
    mString="";
}

std::string MyString::cleanString(std:: string dirtyString)
{
    //ask tutor
   // char x;;
    std::string clean;
    for(std::string::size_type i = 0; i < dirtyString.length(); ++i)
    {
        if(std::isalnum(dirtyString[i]))
        {
           clean+=dirtyString[i];
        }
    }

    return clean;
}

MyString::MyString(std::string instring)
{
    mString=cleanString(instring);
}

MyString::~MyString()
{

}

void MyString::print()
{
    std::cout<<mString<<std::endl;
}

std::string MyString::operator+(std::string rhs)
{
    std::string str=mString+rhs;

    return cleanString(str);
}

std::string MyString::operator+(const MyString& rhs)
{
    std::string combine=mString+rhs.mString;

    return cleanString(combine);
}

MyString& MyString::operator+=(const MyString& rhs)
{
    cleanString(mString)+=cleanString(rhs.mString);
    return *this;
}

bool MyString::operator<(const MyString& rhs)
{
    if(cleanString(mString)<cleanString(rhs.mString))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MyString::operator>(const MyString& rhs)
{
     if(cleanString(mString)>cleanString(rhs.mString))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MyString::operator==(const MyString& rhs)
{
    if(cleanString(mString)==cleanString(rhs.mString))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MyString::operator!=(const MyString& rhs)
{
    
    if(cleanString(mString)!=cleanString(rhs.mString))
    {
        return true;
    }
    else
    {
        return false;
    }
}

MyString& MyString::operator=(const std::string input)
{
    mString=cleanString(input);
    return *this;
}

MyString& MyString::operator=(const MyString& rhs)
{
     mString=cleanString(rhs.mString);
    return *this;
}

MyString& MyString::operator=(std::fstream& file)
{
    if(!file.is_open())
    {
        return *this;
    }

    mString="";

    char getter;

    while(file.get(getter))
    {
        mString+=getter;
    }

    mString=cleanString(mString);

    file.close();

    return *this;
}

void MyString::clear()
{
    mString.clear();
}

bool MyString::operator!()
{
    if(mString.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}