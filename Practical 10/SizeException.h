#ifndef SIZEEXCEPTION_H
#define SIZEEXCEPTION_H
#include "ListException.h"
#include<string>

class SizeException:public ListException
{
    private:
        int m_size;

    public:
        SizeException(int size);
        std::string getError();    
};

#endif