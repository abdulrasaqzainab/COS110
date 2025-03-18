#ifndef BULK_H
#define BULK_H

//import libs
#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "product.h"

class bulk:public product
{
    private:
        float discountPercentage;
        int discountAmount;

    public:
        bulk(std::string n,int bN,int v,int a,float dP,int dA);
        ~bulk();
        virtual float price(std::string s);
        virtual void print();
};

#endif

