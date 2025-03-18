#ifndef BRUTE_H
#define BRUTE_H
#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#include "Soldier.h"
//#include "ShadowBone.h"
//#include "Brute.h"
#include "Ninja.h"

class Soldier;
class Mage;
class Ninja;

class Brute:public Soldier
{
    private:
        double rageMeter;

    public:
        Brute(std::string name,double health,double strength);
        std::string printSoldier();
        Brute& operator=(const Brute& brute);
        bool attack(Brute* brute);
        bool attack(Mage* mage);
        bool attack(Ninja* ninja);    
        
};

#endif