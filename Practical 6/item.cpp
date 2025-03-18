#include "item.h"
//import libs
#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>

item::item(std::string n,int bN)
{
    name=n;
    barcodeLength=0;

    //to bin
    int temp=bN;

   while(temp>0)
   {
    //temp=temp/2;
    barcodeLength++;
    temp>>=1;
   }
    
 /*if(barcodeLength==0)
 {
    barcodeLength=1;
 }   */

//delete[] barcode;
 barcode=new bool[barcodeLength];

 temp=bN;

for(int x=barcodeLength-1 ;x>=0;x--)
{
    barcode[x]=(temp&1);
    temp=temp/2;
}

}

item::~item()
{
    delete[] barcode;
}

std::string item::getName()
{
    return name;
}

std::string item::getBarcode()
{

    std::string mystr="[";

    for(int x=0;x<barcodeLength;x++)
    {
        if(barcode[x]==true)
        {
            mystr+="|";
        }
        else
        {
            mystr+=" ";
        }

    }

    mystr+="](";

    std::stringstream ss;

    ss<<barcodeLength;

std::string nstring=ss.str();

    int original=0;

    int bitval=1;

    for(int x=barcodeLength-1;x>=0;x--)
    {
        if(barcode[x]==true)
        {
            original+=bitval;
        }
        bitval<<=1;
    }
    ss.str("");
    ss<<original;

    mystr+=ss.str();

    mystr+=")";
    return mystr;
}

