#ifndef PRODUCT_H
#define PRODUCT_H

//import libs
#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "item.h"


class product:public item
{
    protected:
        int value;
        int amount;

    public:
        product(std::string,int bN,int v,int a);
        ~product();
        virtual void buy(std::string s);
        virtual float price(std::string s);
        virtual void print();
};

#endif

