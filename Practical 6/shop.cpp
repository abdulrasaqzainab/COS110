
#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "item.h"
#include "shop.h"


shop::shop()
{
    items=NULL;
    numItems=0;
}

shop::~shop()
{
    for(int x=0;x<numItems;x++)
    {
        delete items[x];
    }

    delete[] items;
    items=NULL;
}

int shop::itemIndex(std::string n)
{
    for(int x=0;x<numItems;x++)
    {
        if(items[x]->getName()==n)
        {
            return x;
        }
    }

    return -1;
}

void shop::addItem(item* i)
{
    int idx=itemIndex(i->getName());

    if(idx!=-1)
    {
        std::cout<<"Item already in shop\n";
    }
    else
    {
        item** temp=new item*[numItems+1];
        for(int x=0;x<numItems;x++)
        {
            temp[x]=items[x];
        }

        temp[numItems]=i;

        delete[] items;

        items=temp;
        numItems++;
    }
}
       
void shop::addItems(item** i,int n)
{
    for(int x=0;x<n;x++)
    addItem(i[x]);
}

void shop::buyItems(std::string s)
{
   std::stringstream ss(s);


    std::string mystr;

    float total = 0;
    while(getline(ss,mystr,'|')){
        
        std::string name=mystr.substr(0,mystr.find(':'));
        int idx=shop::itemIndex(name);
        if(idx==-1){
            std::cout<<"Couldn't find "<<name<<std::endl;
            continue;
        }
       
        std::string mystr2=mystr.substr(mystr.find(':'));
       
        total+=items[idx]->price(mystr2);
       
        items[idx]->buy(mystr2);
        
    }
    std::cout<<"Total: R "<<std::fixed<<std::setprecision(2)<<total<<std::endl;
}

void shop::printItems()
{
    for(int x=0;x<numItems;x++)
    {
        items[x]->print();
    }
}

void shop::removeItem(std::string s)
{
    int idx=itemIndex(s);
    int store=numItems-1;

    if(idx!=-1)
    {

        delete items[idx];

        for(int x=idx;x<store;x++)
        {
            items[x]=items[x+1];
        }

        numItems=numItems-1;

        item** temp=new item*[numItems];

        for(int x=0;x<numItems;x++)
        {
            temp[x]=items[x];
        }

        delete[] items;

        items=temp;

    }
    else{
    std::cout<<"Item not found"<<"\n";
    }
}