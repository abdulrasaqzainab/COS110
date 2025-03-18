#ifndef SHADOWBONE_H
#define SHADOWBONE_H

#include "Sword.h"
#include<iostream>
#include<sstream>
#include<string>
#include<cmath>

class Sword;

class ShadowBone:public Sword
{
    private:
        double magicMultiplier;

    public:
    ShadowBone(std::string name,double attack,double magicMultiplier);
    ShadowBone(const ShadowBone& shadowBone);
    double damage(int playerLevel);
    std::string printSword();

};


#endif