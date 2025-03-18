#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "item.h"
#include "product.h"

product::product(std::string n,int bN,int v,int a):item(n,bN)
{
    value=v;
    amount=a;
}

product::~product()
{
    //is there anthing to kill?
}

void product::buy(std::string s)
{
    int quant;

std::istringstream iss(s);

iss>>quant;

    if(quant>amount)
    {
        quant=amount;
    }

    float total=quant*value;

    amount=amount-quant;
 //std::cout<<price(s)<<std::endl;
    std::cout<<"Bought{"<<quant<<"}{"<<name<<"}{R"<<std::fixed<<std::setprecision(2)<<total<<"}\n";

}

float product::price(std::string s)
{
    //int amo=atoi(s.c_str());

int amo;

std::istringstream iss(s);

iss>>amo;


    if(amo>amount)
    {
        amo=amount;
    }

    float total=amo*value;

    return total;
}

void product::print()
{
   std::cout<<"product{"<<getBarcode()<<"}{"<<name<<"}{R"
            <<std::fixed<<std::setprecision(2)<<value<<"}"
            <<"{"<<amount<<"}\n";
}