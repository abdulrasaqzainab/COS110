#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "product.h"
#include "bulk.h"

bulk::bulk(std::string n,int bN,int v,int a,float dP,int dA):product(n,bN,v,a)
{
    discountPercentage=dP;
    discountAmount=dA;
}

bulk::~bulk()
{
//do nothing
}

float bulk::price(std::string s)
{
   int quant;

std::istringstream iss(s);

if(!(iss>>quant))
{
    return 0.0;
}

if(discountAmount==0)
{
    return quant*value;
}


   int count=quant/discountAmount;
   int remian=quant%discountAmount;

   float discount=count*discountAmount*value*discountPercentage;

float nodiscount=remian*value;

float total=quant*value-discount+nodiscount;




    return total;
}

void bulk::print()
{
    std::cout<<"bulk{"<<getBarcode()<<"}{"<<name<<"}{R"
            <<std::fixed<<std::setprecision(2)<<value
            <<"}{"<<amount
            <<"}{"<<discountPercentage*100
            <<"%}{"<<discountAmount<<"}"<<"\n";

}