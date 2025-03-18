#ifndef NINJA_H
#define NINJA_H
#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#include "Soldier.h"
//#include "ShadowBone.h"
#include "Brute.h"
#include "Mage.h"
#include "Sword.h"
//#include "Ninja.h"

class Soldier;
class Brute;
class Mage;

class Ninja:private Soldier
{
   private:
        int moveCount;

    public:
        Ninja(std::string name,double health,double strength);
        bool takeDamage(double damage);
        Ninja& operator=(const Ninja& ninja);
        bool isAlive() const;
        bool attack(Brute* brute);
        bool attack(Mage* mage);
        bool attack(Ninja* ninja); 
        void arm(Sword* sword);
       
       
       
};
#endif