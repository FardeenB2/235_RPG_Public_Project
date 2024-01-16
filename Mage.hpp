/*
File Title: Mage.hpp
email: fardeen.bhuiyan70@myhunter.cuny.edu
Author: Fardeen Bhuiyan
Brief Description: This program uses Project 1's fantasy character cpp and hpp, and inherits from that so that we have multiple subclasses of warriors
that each have their own unique tools and functions and attributes.
Date of Submission: September 22, 2023
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_
#include <iostream>
using namespace std;
#include <string>
#include <cctype>

#include "Character.hpp"

//Note to implement, these are all supposed to be inherited from the superclass.

class Mage : public Character
{
    public:


        Mage();

        Mage(const string& name, const string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy=false, 
        const string& magic_school = "NONE", const string& weapon = "NONE", bool can_incarnate=false);

        bool setSchool (const string& magic_school);            //this is not referencing the parameters of the constructor above, they just have the same parameter names
        
  
        string getSchool() const;                            

        bool setCastingWeapon (const string& weapon);

  
        string getCastingWeapon() const;


        void setIncarnateSummon(const bool& incarnate);   

     
        bool hasIncarnateSummon() const;



    private:

        string school_of_magic_;
        string weapon_;
        bool summon_incarnate_;


};

#endif
