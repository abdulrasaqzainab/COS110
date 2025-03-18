#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "product.h"
#include "discountedProduct.h"

discountedProduct::discountedProduct(std::string n,int bN,int v,int a,float d):product(n,bN,v,a)
{
    discount=d;
}

discountedProduct::~discountedProduct()
{
//do nothing
}

float discountedProduct::price(std::string s)
{
 int quant;

std::istringstream iss(s);

iss>>quant;

 float total=quant*value*(1-discount);

return total;

}

void discountedProduct::print()
{
    std::cout<<"discountedProduct{"<<getBarcode()<<"}{"<<name<<"}{R"
            <<std::fixed<<std::setprecision(2)<<value
            <<"}{"<<amount<<"}{"
            <<discount*100<<"%}"<<"\n";

}