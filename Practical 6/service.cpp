#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "item.h"
#include "service.h"

service::service(std::string n,int bN,int r,char p):item(n,bN)
{
    rate=r;
    period=p;
}

service::~service()
{
    //nothing to kill
}

void service::buy(std::string s)
{
    float time=0;

    char  input;

    std::istringstream iss(s);

    iss>>time>>input;

//    period=input;
//int mult=1;
float total;
//int div=0;
float hours;
std::string out;
     

if(period=='h')
{
    if(input=='h')
    {
        total=(time*rate)/1;
    }
    else if(input=='d')
    {
        total=(time*rate*24)/1;
    }
    else if(input=='w')
    {
        total=(time*rate*24*7)/1;
    }
    else if(input=='m')
    {
        total=(time*rate*24*7*4)/1;
    }
    else
    {
       total=(time*rate*24*7*4*12)/1;
    }
    
}

else if(period=='d')
{
    if(input=='h')
    {
        total=(time*rate)/24;
    }
    else if(input=='d')
    {
        total=(time*rate*24)/24;
    }
    else if(input=='w')
    {
        total=(time*rate*24*7)/24;
    }
    else if(input=='m')
    {
        total=(time*rate*24*7*4)/24;
    }
    else
    {
        total=(time*rate*24*7*4*12)/24;
    }
    
}

else if(period=='w')
{
    if(input=='h')
    {
        total=(time*rate)/(7*24);
    }
    else if(input=='d')
    {
        total=(time*rate*24)/(7*24);
    }
    else if(input=='w')
    {
        total=(time*rate*7*24)/(7*24);
    }
    else if(input=='m')
    {
        total=(time*rate*4*7*24)/(7*24);
    }
    else
    {
        total=(time*rate*12*4*7*24)/(7*24);
    }
    
}

else if(period=='m')
{
    if(input=='h')
    {
        total=(time*rate)/(7*24*4);
    }
    else if(input=='d')
    {
        total=(time*rate*24)/(7*24*4);
    }
    else if(input=='w')
    {
        total=(time*rate*7*24)/(7*24*4);
    }
    else if(input=='m')
    {
        total=(time*rate*4*7*24)/(7*24*4);
    }
    else
    {
        total=(time*rate*12*4*7*24)/(7*24*4);
    }
    
    
}

else
{
   if(input=='h')
    {
        total=(time*rate)/(7*24*4*12);
    }
    else if(input=='d')
    {
        total=(time*rate*24)/(7*24*4*12);
    }
    else if(input=='w')
    {
        total=(time*rate*7*24)/(7*24*4*12);
        //total=1/total;
    }
    else if(input=='m')
    {
        total=(time*rate*4*7*24)/(7*24*4*12);
    }
    else
    {
        total=(time*rate*12*4*7*24)/(7*24*4*12);
    
    }
}

switch(input)
    {
        case 'h':
            out="hours";
            break;
        case 'd':
            out="days";
            break;
        case 'm':
            out="months";
            break;
        case 'w':
            out="weeks";
            break;
        case 'y':
    
        default:
                out="years";
        //break;
    }

    // if(time>1)
    // out+="s";
//int ttime=time*mult;

//total=(rate*time)/hours;
    //float total=(rate*ttime)/mult;
    //total/=div;
    //total/=7;
    int ctime=time;
   
//std::cout<<price(s)<<std::endl;
    std::cout<<"Bought{"<<ctime
             <<out<<"}{"<<name<<"}";
             std::cout<<"{R"
             <<std::fixed<<std::setprecision(2)<<price(s)<<"}\n";
}

float service::price(std::string s)
{
    //int total=0;

     float time=0;
     float total;

    char  input;

    std::istringstream iss(s);

    iss>>time>>input;

 
    std::string out;

    if(period=='h')
{
    if(input=='h')
    {
        total=(time*rate)/1;
       // total=total*value;
    }
    else if(input=='d')
    {
        total=(time*rate*24)/1;
    }
    else if(input=='w')
    {
        total=(time*rate*24*7)/1;
    }
    else if(input=='m')
    {
        total=(time*rate*24*7*4)/1;
    }
    else
    {
       total=(time*rate*24*7*4*12)/1;
    }
    
}

else if(period=='d')
{
    if(input=='h')
    {
        total=(time*rate)/24;
    }
    else if(input=='d')
    {
        total=(time*rate);
    }
    else if(input=='w')
    {
        total=(time*rate*7);
    }
    else if(input=='m')
    {
        total=(time*rate*7*4);
    }
    else
    {
        total=(time*rate*7*4*12);
    }
    
}

else if(period=='w')
{
    if(input=='h')
    {
        total=(time*rate)/(7*24);
    }
    else if(input=='d')
    {
        total=(time*rate)/(7);
    }
    else if(input=='w')
    {
        total=(time*rate);
    }
    else if(input=='m')
    {
        total=(time*rate*4);
    }
    else
    {
        total=(time*rate*12*4);
    }
    
}

else if(period=='m')
{
    if(input=='h')
    {
        total=(time*rate)/(7*24*4);
    }
    else if(input=='d')
    {
        total=(time*rate)/(7*4);
    }
    else if(input=='w')
    {
        total=(time*rate)/(4);
    }
    else if(input=='m')
    {
        total=(time*rate);
    }
    else
    {
        total=(time*rate*12);
    }
    
    
}

else
{
   if(input=='h')
    {
        total=(time*rate)/(7*24*4*12);
    }
    else if(input=='d')
    {
        total=(time*rate)/(7*4*12);
    }
    else if(input=='w')
    {
        total=(time*rate)/(4*12);
        //total=1/total;
    }
    else if(input=='m')
    {
        total=(time*rate)/(12);
    }
    else
    {
        total=(time*rate);
    
    }
}


    return total;
}

void service::print()
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

    std::cout<<"service{"<<getBarcode()<<"}{"<<name<<"}{R"
            <<std::fixed<<std::setprecision(2)<<rate
            <<std::fixed<<std::setprecision(2)<<"/"<<out<<"}\n";

}


