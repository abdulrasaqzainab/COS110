#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "Soldier.h"
#include "ShadowBone.h"
#include "Brute.h"
#include "Ninja.h"
#include "Sword.h"

Ninja::Ninja(std::string name, double health, double strength) : Soldier(name, health, strength)
{
    moveCount = 0;
}

bool Ninja::takeDamage(double damage)
{
    if (moveCount == 2)
    {
        moveCount = 0;
        return false;
    }

    moveCount++;
    return Soldier::takeDamage(damage); // am i using recursion?
}

Ninja &Ninja::operator=(const Ninja &ninja)
{
    if (this == &ninja)
    {
        return *this;
    }

    Soldier::operator=(ninja);

    //     if(this->sword!=ninja.sword)
    //     {
    //         delete this->sword;
    //         this->sword=NULL;
    //     }

    // if(ninja.sword!=NULL)
    // {
    //     this->sword=new Sword(*ninja.sword);
    // }
    moveCount = ninja.moveCount;

    return *this;
}

bool Ninja::isAlive() const
{
    return Soldier::isAlive();
}

bool Ninja::attack(Brute *brute)
{
    if (brute == NULL || !brute->isAlive() || sword == NULL)
    {
        return false;
    }

    // if(sword!=NULL)
    double damages = sword->damage(strength);

    bool is_dead = brute->takeDamage(damages);

    if (is_dead == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Ninja::attack(Ninja *ninja)
{

    if (!ninja || !ninja->isAlive() || sword == NULL)
    {
        return false;
    }

    double damages = sword->damage(strength);
    bool is_dead = ninja->takeDamage(damages);

    if (is_dead == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Ninja::attack(Mage *mage)
{
    if (!mage || !mage->isAlive() || sword == NULL)
    {
        return false;
    }

    double damages = sword->damage(strength);

    bool is_dead = mage->takeDamage(damages);

    if (is_dead == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Ninja::arm(Sword *sword)
{
    Soldier::arm(sword);
}