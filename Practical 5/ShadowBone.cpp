#include "ShadowBone.h"
#include "Sword.h"
#include<iostream>
#include<sstream>
#include<string>
#include<cmath>

//public sword

ShadowBone::ShadowBone(std::string name,double attack,double magicMultiplier):Sword(name,attack)
{
    this->magicMultiplier=magicMultiplier;
}

ShadowBone::ShadowBone(const ShadowBone& shadowBone):Sword(shadowBone)
{
    this->magicMultiplier=shadowBone.magicMultiplier;

}

double ShadowBone::damage(int playerLevel)
{
 double part1=level*0.2;
 double part2=playerLevel*0.1;

double temp=attack+(attack*((part2+part1)+magicMultiplier));
addXP(temp);
return temp;
}

std::string ShadowBone::printSword()
{
 std::string combination=Sword::printSword();

std::stringstream ss;
    
    ss<<magicMultiplier;

    std::string magicMultipliers=ss.str();

 combination+="Magic Multiplier: "+magicMultipliers+"\n";

 return combination;     

}