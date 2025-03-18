#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H

//import libs
#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "service.h"

class subscription:public service
{
    private:
        float yearDiscount;
    public:
        subscription(std::string n,int bN,int r,char p,float d);
        ~subscription();
        virtual float price(std::string s);
        virtual void print();    
};

#endif

