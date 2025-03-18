#ifndef MAGE_H
#define MAGE_H
#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#include "Soldier.h"
#include "ShadowBone.h"
#include "Brute.h"
#include "Ninja.h"

class Soldier;
class Ninja;
class Brute;

class Mage:public Soldier
{
    private:
        ShadowBone* shadowBone;

    public:
        Mage(std::string name,double health,double strength);
        void armShadow(ShadowBone *shadowBone);
        Mage& operator=(const Mage& mage);
        std::string printSoldier();
        bool attack(Brute* brute);
        bool attack(Mage* mage);
        bool attack(Ninja* ninja);
};

#endif