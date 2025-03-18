#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "service.h"
#include "subscription.h"

subscription::subscription(std::string n,int bN,int r,char p,float d):service(n,bN,r,p)
{
    yearDiscount=d;
}

subscription::~subscription()
{
//do  nothing
}

float subscription::price(std::string s)
{
    float dis;
    char per;

std::istringstream iss(s);

iss>>dis>>per;


    if(per=='y')
    {
        float discount=rate*(1-yearDiscount);
        return dis*discount;
    }

    return dis*rate;
}

void subscription::print()
{

    std::string out;
    switch(period)
    {
        case 'h':
            //mult=1;
            out="hour";
            break;
        case 'd':
            //mult=24;
            out="day";
            break;
        case 'm':
            //mult=24*30;
            out="month";
            break;
        case 'w':
            //mult=24*7;
            out="week";
            break;
        case 'y':
    
        default:
        //mult=24*365;
        out="year";
        break;
    }

    std::cout<<"subscription{"<<getBarcode()<<"}{"<<name<<"}{R"
            <<std::fixed<<std::setprecision(2)<<rate
            <<"/"<<out<<"}{"
            <<std::fixed<<std::setprecision(2)
            <<yearDiscount*100<<"%}"<<"\n";

}