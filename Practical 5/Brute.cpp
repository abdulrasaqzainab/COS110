#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#include "Soldier.h"
#include "ShadowBone.h"
#include "Brute.h"
#include "Ninja.h"

Brute::Brute(std::string name,double health,double strength):Soldier(name,health,strength)
{
    rageMeter=0;
}

std::string Brute::printSoldier()
{
    std::string printt=Soldier::printSoldier();

std::stringstream ss;

    ss<<rageMeter;
    std::string healths=ss.str();
    printt+="Rage meter: "+healths+"\n";

    //printt+="Rage meter: "+


    return printt;
}

Brute& Brute::operator=(const Brute& brute)
{
    if(this==&brute)
    {
        return *this;
    }

    Soldier::operator=(brute);

    rageMeter=brute.rageMeter;

    return *this;

}

bool Brute::attack(Mage* mage)
{
    if(mage==NULL || !mage->isAlive() || sword==NULL)
    {
        return false;
    }

       double damages=strength*2;

       if(rageMeter>10 || rageMeter==10)
       {
        damages+=strength*(rageMeter-10)*0.1;
       }

       bool death=mage->takeDamage(damages);

       if(death==true)
       {
        rageMeter=0.0;
        return true;
       }
       else
       {
        rageMeter+=1;
        return false;
       }
}

bool Brute::attack(Ninja* ninja)
{
    if(ninja==NULL || !ninja->isAlive() || sword==NULL)
    {
        return false;
    }


    double damages=strength*2;

       if(rageMeter>10 || rageMeter==10)
       {
        damages+=strength*(rageMeter-10)*0.1;
       }

       bool death=ninja->takeDamage(damages);

       if(death==true)
       {
        rageMeter=0.0;
        return true;
       }
       else
       {
        rageMeter+=1;
        return false;
       }
}

bool Brute::attack(Brute* brute)
{
    if(!brute || !brute->isAlive() || !sword)
    {
        return false;
    }

    double damages=strength*2;

       if(rageMeter>10 || rageMeter==10)
       {
        damages+=(strength*(rageMeter-10)*0.1)*0.5;
       }

       bool death=brute->takeDamage(damages);

       if(death==true)
       {
        rageMeter=0.0;
        return true;
       }
       else
       {
        rageMeter+=1;
        return false;
       }
}