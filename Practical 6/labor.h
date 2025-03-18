#ifndef LABOR_H
#define LABOR_H

//import libs
#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "service.h"

class labor:public service
{
    private:
        int* workerRates;
        int numWorkers;
    public:
        labor(std::string n,int bN,int r,char p,int*wR,int num);
        ~labor();
        virtual float price(std::string s);
        virtual void print();
};

#endif

