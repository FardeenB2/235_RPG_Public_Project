/*
File Title: Scoundrel.hpp
email: fardeen.bhuiyan70@myhunter.cuny.edu
Author: Fardeen Bhuiyan
Brief Description: This program uses Project 1's fantasy character cpp and hpp, and inherits from that so that we have multiple subclasses of warriors
that each have their own unique tools and functions and attributes.
Date of Submission: September 22, 2023
*/
#ifndef SCOUNDREL_HPP_
#define SCOUNDREL_HPP_
#include <iostream>
using namespace std;
#include <string>
#include <cctype>

#include "Character.hpp"


enum Dagger 
{
    WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE
};



class Scoundrel : public Character
{
    public:

        Scoundrel();

        Scoundrel(const string& name, const string& race, int vitality=0, int armor=0, int level=0, bool enemy=false,
        const string& dagger = "WOOD", const string& faction = "NONE", bool disguise=false);

        void setDagger (const string& dagger);

        string getDagger() const;

        bool setFaction (const string& faction);

  
        string getFaction() const;

        void setDisguise(const bool& disguise);


        bool hasDisguise() const;


    private:

        Dagger dagger_;
        string faction_;
        bool disguise_; 


};

#endif
