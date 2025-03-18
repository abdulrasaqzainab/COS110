#ifndef SHOP_H
#define SHOP_H

//import libs
#include<cmath>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include "item.h"

class shop
{
    private:
        int numItems;
        item** items;
    public:
        shop();
        ~shop();
        int itemIndex(std::string n);
        void addItem(item* i);
        void addItems(item** i,int n);
        void buyItems(std::string s);
        void printItems();
        void removeItem(std::string s);

};

#endif

