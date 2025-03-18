#ifndef ITEM_H
#define ITEM_H

//import libs
#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>

class item
{
    protected:
        std::string name;
        int barcodeLength;
        bool* barcode;
    public:
        item(std::string,int bN);
        ~item();
        std::string getName();
        std::string getBarcode();
        virtual void buy(std::string s)=0;
        virtual float price(std::string s)=0;
        virtual void print()=0;    
    
};

#endif

