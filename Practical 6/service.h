#ifndef SERVICE_H
#define SERVICE_H

//import libs
#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "item.h"

class service:public item
{
    protected:
        int rate;
        char period;

    public:
        service(std::string n,int bN,int r,char p);
        ~service();
        virtual void buy(std::string s);
        virtual float price(std::string s);
        virtual void print();    
};

#endif

