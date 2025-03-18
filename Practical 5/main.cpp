#include <iostream>
#include <sstream>
#include <string>
#include "Sword.h"
#include "Mage.h"
#include "Brute.h"
#include "Ninja.h"
#include "Soldier.h"
#include "ShadowBone.h"


void Sword_test()
{
   
}

void MNB_test()
{
   
}

// void Brute_test()
// {

// std::cout<<"\n";
// }

// void Ninja_test()
// {

// std::cout<<"\n";
// }



int main(){

   // ShadowBone_test();
     Sword mysword1("biggie",23);
    std::cout<<mysword1.printSword()<<std::endl;
    std::cout<<"Damage :"<<mysword1.damage(5)<<std::endl;

    Sword newSword=mysword1;

    std::cout<<newSword.printSword()<<std::endl;
    std::cout<<newSword.damage(100)<<std::endl;
std::cout<<"__________________________________________________________________________________________"<<std::endl;
   // Sword_test();
 
    Brute brute("Zainab", 600.0, 12.0);
    Ninja ninja("Nico", 190.0, 9.0);
    Mage mage("Tati", 570.0, 7.0);

    
    Sword sword2("Sharp", 18.0);
    //ninja.arm(&sword2);

    
    ShadowBone shadowBone2("Blue Sharp", 22.0, 11.0);
  //  mage.armShadow(&shadowBone2);
//
      std::cout<<"Nico attacks Zainab->"<<ninja.attack(&brute)<<std::endl;
    std::cout<<"Tati attacks Zainab->"<< mage.attack(&brute)<<std::endl;

//zero is false

   std::cout<<"Tati attacks Zainab again->"<< mage.attack(&brute)<<std::endl;

    std::cout<<"IM LOOKING HERE_________________________________________\n";
    std::cout<<brute.printSoldier()<<std::endl;
   
    std::cout<<mage.printSoldier()<<std::endl;

     //Soldier soldier1("Soldier1", 100.0, 10.0);
    Brute brute1("Brute1", 150.0, 15.0);
     Mage mage1("Mage1", 120.0, 12.0);
    Ninja ninja1("Ninja1", 80.0, 8.0);

    // Create instances to assign values from
  //Soldier soldier2("Soldier2", 50.0, 5.0);
    Brute brute2("Brute2", 75.0, 7.5);
     Mage mage2("Mage2", 60.0, 6.0);
 Ninja ninja2("Ninja2", 40.0, 4.0);

//     // Perform assignment using assignment operators
  
   brute1 = brute2;
     mage1 = mage2;
    ninja1 = ninja2;

     
    std::cout << "Mage attacks Brute: " << mage.attack(&brute) << std::endl;
    std::cout << "Brute attacks Brute: " << brute.attack(&brute) << std::endl;
    std::cout << "Ninja attacks Brute: " << ninja.attack(&brute) << std::endl;


 std::cout << "Mage attacks Ninja: " << mage.attack(&ninja) << std::endl;
     std::cout << "Brute attacks Ninja: " << brute.attack(&ninja) << std::endl;
     std::cout << "Ninja attacks Ninja: " << ninja.attack(&ninja) << std::endl;


std::cout << "Mage attacks Mage: " << mage.attack(&mage) << std::endl;
  std::cout << "Brute attacks Mage: " << brute.attack(&mage) << std::endl;
    std::cout << "Ninja attacks Mage: " << ninja.attack(&mage) << std::endl;



std::cout<<"\n";
std::cout<<"__________________________________________________________________________________________"<<std::endl;
   // Soldier_test();
    Soldier soldier1("Lancealot",185.0,97.0);
    Soldier soldier2("James",38.4,3.0);
soldier1 = soldier2;
    
    Sword sword1("Hammer", 15);
    ShadowBone shadowBone1("Arrow", 21.3, 6.7);

    
     //soldier1.arm(&sword1);
    // soldier2.arm(&shadowBone1);



    std::cout<<soldier1.printSoldier()<<"\n"<<sword1.printSword()<<std::endl;
    std::cout<<soldier2.printSoldier()<<"\n"<<shadowBone1.printSword()<< std::endl;

std::cout<<"\n";
std::cout<<"__________________________________________________________________________________________"<<std::endl;
    
//MNB_test(); ShadowBone shadow1("The_first",54,23);

   // ShadowBone newShadow1=shadow1;

   // std::cout<<shadow1.printSword()<<std::endl;
   // std::cout<<"Damage:"<<shadow1.damage(8)<<std::endl;



    //std::cout<<newShadow1.printSword()<<std::endl;

std::cout<<"\n";
    return 0;
}