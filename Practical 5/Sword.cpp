#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#include "Sword.h"

Sword::Sword(std::string name,double attack)
{
    level=1;
    xp=0;
    this->attack=attack;
    this->name=name;
}

int Sword::getXPForNextLevel()
{
    double store=level+1;
    double store2=2*store;
    double storeln=log(store2);
    double storepow=pow(storeln,3.00);
    int out=storepow;

    xp=out;

    //std::cout<<xp<<std::endl;

    return out;
}

void Sword::addXP(double damage)
{
//  double newdamage=0.1*damage;
//  xp+=newdamage;

// if(xp>getXPForNextLevel() || xp==getXPForNextLevel())
// {
//     level+=1;
//     xp=xp-getXPForNextLevel();
//}
xp=xp+(0.1*damage );
if(xp> getXPForNextLevel() || xp==getXPForNextLevel())
{
    level++;
    xp=0;
}
}

double Sword::damage(int playerStrength)
{
//  double part1=level*0.2;
//  double part2=playerStrength*0.1;

 double keep=attack+attack*(playerStrength*0.1 + level*0.2);

addXP(keep);

return keep;
}

std::string Sword::printSword()
{
    //std::cout<<"Sword: "<<name<<"\n";
    std::stringstream ss;
    
    ss<<attack;

    std::string attacks=ss.str();
     ss.str("");
    ss.clear();
    ss<<level;

    std::string levels=ss.str();
 ss.str("");
    ss.clear();
    ss<<xp;
    std::string xps=ss.str();

    std::string comb;

    comb="Sword: "+name+"\n"
        +"Attack: "+attacks+"\n"
        +"Level: "+levels+"\n"
        +"XP: "+xps+"\n";

     return comb;   

}

Sword::Sword(const Sword& sword)
{
    name=sword.name;
    level=sword.level;
    xp=sword.xp;
    attack=sword.attack;
}