#include "ConstructorException.h"
#include "ListException.h"
#include<iostream>
#include<string>

std::string ConstructorException::getError()
{
    return "Invalid parameter.";
}