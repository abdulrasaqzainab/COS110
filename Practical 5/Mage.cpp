#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#include "Soldier.h"
#include "ShadowBone.h"
#include "Brute.h"
#include "Ninja.h"
#include "Mage.h"

Mage::Mage(std::string name,double health,double strength):Soldier(name,health,strength)
{
//do i need to put anything in here?
shadowBone=NULL;

}

void Mage::armShadow(ShadowBone *shadowBone)
{
    if(shadowBone==NULL)
    {
        return;
    }

    if(shadowBone==this->shadowBone)
    {
        return;
    }

   delete this->shadowBone;
    this->shadowBone=shadowBone;
}

Mage& Mage::operator=(const Mage& mage)
{
    if(&mage==this)
    {
        return *this;
    }

    Soldier::operator=(mage);

    if(this->shadowBone)   
    delete shadowBone;

    if(mage.shadowBone)
    {
        shadowBone=new ShadowBone(*mage.shadowBone);
    }
    else
    {
        shadowBone=NULL;
    }

    return *this;
}

std::string Mage::printSoldier()
{
    std::string printt=Soldier::printSoldier();

    if(shadowBone!=NULL)
    {
        printt+=shadowBone->printSword()+"\n";
    }

    return printt;
}

bool Mage::attack(Brute* brute)
{

    if(!brute || !brute->isAlive() || !shadowBone)
    {
        return false;
    }
    //look at rules for attack
    if(shadowBone!=NULL)
    {
        double damages=shadowBone->damage(strength);
        return brute->takeDamage(damages);
    }

    
        double damages=sword->damage(strength);

        bool death=brute->takeDamage(damages);
        //return 
    

    if(death==true)
    {
        return true;
    }
    else{
        return false;
    }
    //return false;
}   

bool Mage::attack(Ninja* ninja)
{
if(!ninja || !ninja->isAlive() || !shadowBone)
    {
        return false;
    }

    //look at rules for attack
    if(shadowBone!=NULL)
    {
        double damages=shadowBone->damage(strength);
        return ninja->takeDamage(damages);
    }

    
        double damages=sword->damage(strength);
        bool death=ninja->takeDamage(damages);
        //return 
    

    if(death==true)
    {
        return true;
    }
    else{
        return false;
    }
    
}


bool Mage::attack(Mage* mage)
{
    //look at rules for attack
if(!mage || !mage->isAlive() || !shadowBone)
    {
        return false;
    }


    //returning using damage
       double damages = (shadowBone != NULL) ? shadowBone->damage(strength) : sword->damage(strength);
    
        bool death=mage->takeDamage(damages);
        //return 
    

    if(death==true)
    {
        return true;
    }
    else{
        return false;
    }
   
}





