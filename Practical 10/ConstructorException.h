#ifndef CONSTRUCTOREXCEPTION_H
#define CONSTRUCTOREXCEPTION_H
#include "ListException.h"
#include <string>

class ConstructorException:public ListException
{
    public: 
    std::string getError();   
};

#endif