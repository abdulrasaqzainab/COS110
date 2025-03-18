#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "service.h"
#include "labor.h"

labor::labor(std::string n,int bN,int r,char p,int* wR,int num):service(n,bN,r,p)
{
 numWorkers=num;
 workerRates=new int[numWorkers];

 for(int x=0;x<numWorkers;x++)
 {
    workerRates[x]=wR[x];
 }   
}

labor::~labor()
{
    delete[] workerRates;
}

float labor::price(std::string s)
{
    float time;
    char input;
    float ratehold=rate;

std::istringstream iss(s);

iss>>time>>input;


    float total=0;

    int mult;

    std::string out;
    


/*
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
}*/

if(input!='h')
{
    if(input!='d')
    {
        if(input!='w')
        {
            if(input!='m')
            {
                if(input!='y')
                {
                    input='y';
                }
            }
        }
    }
}

switch(period)
{
    case 'h':
        ratehold/=1;
        break;
    case 'd':
        ratehold/=(24);
        break;
    case 'w':
        ratehold/=(24*7);
        break;
    case 'm':
        ratehold/=(24*7*4);
        break;
    case 'y':

        
    default:
        ratehold/=(24*7*4*12);
        break;              

}

switch(input)
{
    case 'h':
        ratehold*=time;
        break;
    case 'd':
        ratehold*=(24*time);
        break;
    case 'w':
        ratehold*=(24*7*time);
        break;
    case 'm':
        ratehold*=(24*7*4*time);
        break;
    case 'y':

        
    default:
        ratehold*=(24*7*4*12*time);
        break;  

}


    
    for(int x=0;x<numWorkers;x++)
    {
        total+=ratehold*workerRates[x];
    }

    return  total;
}

void labor::print()
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

std::cout<<"labor{"<<getBarcode()<<"}{"<<name<<"}{R"
            <<std::fixed<<std::setprecision(2)<<rate
            <<"/"<<out<<"{[";

            for(int x=0;x<numWorkers;x++)
            {
                std::cout<<workerRates[x];
                if(x<(numWorkers-1))
                {
                    std::cout<<",";
                }
            }

            std::cout<<"]}\n";

}


