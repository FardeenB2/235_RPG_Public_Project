/*
File Title: Barbarian.hpp
email: fardeen.bhuiyan70@myhunter.cuny.edu
Author: Fardeen Bhuiyan
Brief Description: This program uses Project 1's fantasy character cpp and hpp, and inherits from that so that we have multiple subclasses of warriors
that each have their own unique tools and functions and attributes.
Date of Submission: September 22, 2023
*/
#ifndef BARBARIAN_HPP_
#define BARBARIAN_HPP_
#include <iostream>
using namespace std;
#include <string>
#include <cctype>

#include "Character.hpp"


//Note to implement, these are all supposed to be inherited from the superclass.

class Barbarian : public Character
{
    public:


        Barbarian();

        Barbarian(const string& name, const string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy=false, 
        const string& main_weapon = "NONE", const string& offhand_weapon = "NONE", bool enraged=false);

        bool setMainWeapon (const string& main_weapon);

        string getMainWeapon() const;


        bool setSecondaryWeapon (const string& offhand_weapon);


        string getSecondaryWeapon() const;


        void setEnrage (const bool& enraged);


        bool getEnrage () const;


        void toggleEnrage();

    private:

        string main_weapon_;
        string offhand_weapon_;
        bool enraged_;

        


};

#endif
