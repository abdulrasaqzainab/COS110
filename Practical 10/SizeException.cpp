#ifndef SIZEEXCEPTION_CPP
#define SIZEEXCEPTION_CPP
#include "SizeException.h"
#include "ListException.h"
#include<iostream>
#include<string>
#include<sstream>

SizeException::SizeException(int size)
{
    this->m_size=size;
}

std::string SizeException::getError()
{
    std::string mystr;
   std::ostringstream oss;
   oss<<m_size;

    std::string m_str = oss.str();

    if(m_size==0)
    {
        return "List is empty.";
    }
    else if(m_size != 0)
    {
        mystr+="List is full with ";
        mystr+=m_str;
        mystr+=" elements.";
    }

    return mystr;
}

#endif