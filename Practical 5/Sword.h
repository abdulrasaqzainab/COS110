#ifndef SWORD_H
#define SWORD_H
#include<iostream>
#include<sstream>
#include<string>
#include<cmath>

class Sword
{
    private:
        std::string name;
    protected:
        int level;
        double xp;
        double attack;    
        int getXPForNextLevel();
        void addXP(double xp);

    public:
        Sword(std::string name,double attack);
        Sword(const Sword& sword);
        std::string printSword();
        double damage(int playerStrength);    
};


#endif