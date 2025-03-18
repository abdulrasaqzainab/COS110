#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#include "Soldier.h"
#include "Sword.h"

int Soldier:: aliveSoldiers=0;
int Soldier::deadSoldiers=0;


Soldier::Soldier(std::string name,double health,double strength)
{
    aliveSoldiers++;
    this->name=name;
    this->health=health;
    this->strength=strength;
    sword=NULL;
}

Soldier::~Soldier()
{

   delete sword;
   sword=NULL;
   
}

std::string Soldier::printSoldier()
{
    std::string out="Name: "+name+"\n";
    //conv health
    std::stringstream ss;

    ss<<health;
    std::string healths=ss.str();
    out+="Health: "+healths+"\n";

    ss.str("");
    ss.clear();
    //conv strength
    ss<<strength;
    std::string streangths=ss.str();
    out+="Strength: "+streangths+"\n";

    if (sword!=NULL)
    {
        out+=sword->printSword();
    }
    
    
 return out;

}

void Soldier::arm(Sword* sword)
{
    if(sword==NULL)
    {
        return;
    }

    if(this->sword!=sword)
    {
        if(this->sword !=NULL)
        {
            delete this->sword;
        }

        this->sword=sword;
    }

   
    // if(sword!=NULL)
    // {
    //     //delete sword;
    //     sword=NULL;
    // }

//  if(this->sword != NULL)
//     {
//         delete this->sword;
// this->sword=sword;
//     }
    
    
}

bool Soldier::takeDamage(double damage)
{
    if(damage<0)
    {
        return false;
    }

    if(health<0 || health==0)
    {
        return false;
    }

    health=health-damage;

   if(health<0 || health==0)
    {
        
        health=0;
        
    aliveSoldiers--;
    deadSoldiers++;
    
    return true;
    }


    return false;
}

bool Soldier::isAlive() const
{
    if(health>0)
    {
        return true;
    }

    return false;
}

Soldier& Soldier::operator=(const Soldier& soldier)
{
    if(this==&soldier)
    {
        return *this;
    }

    this->name=soldier.name;
    this->health=soldier.health;
    this->strength=soldier.strength;

    if(this->sword!=NULL)
    {
        delete this->sword;
        this->sword=NULL;

        
    }

    if(soldier.sword!=NULL)
    {
        sword=new Sword(*soldier.sword);
    }
    else
    {
        sword=NULL;
    }

    return *this;

}