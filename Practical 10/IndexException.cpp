#include "ListException.h"
#include "IndexException.h"
#include <iostream>
#include <string>
#include <sstream>
IndexException::IndexException(int index,int size)
{
    // constructor
    m_index=index;
    m_size=size;
}

std::string IndexException::getError()
{
    std::string mystr;
   std::ostringstream oss;
   oss<<m_size;

    std::string m_str = oss.str();

    std::ostringstream oss1;
   oss1<<m_index;

    std::string m_str1 = oss1.str();
    if(m_index < 0)
    {
        mystr+="Index " ;
        mystr+=m_str1;
        mystr+=" is negative.";

    }   

    else
    {
        mystr+="Index ";
        mystr+=m_str1;
        mystr+=" is out of bounds for list of size ";
        mystr+=m_str;
        mystr+=".";
    }

    return mystr;
}