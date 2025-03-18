#ifndef DISCOUNTEDPRODUCT_H
#define DISCOUNTEDPRODUCT_H

//import libs
#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "product.h"

class discountedProduct:public product
{
    private:
        float discount;
    public:
        discountedProduct(std::string n,int bN,int v,int a,float d);
        ~discountedProduct();
        virtual float price(std::string s);
        virtual void print();    
};

#endif

