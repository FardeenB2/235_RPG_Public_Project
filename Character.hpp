/*
File Title: Character.hpp
Author: Fardeen Bhuiyan
Brief Description: This program creates a Fantasy Character class that contains the data of
name, race, vitality, armor, and level of the character and whether they are an enemy or not.
It can initialize these variables and alter them anytime.
Date of original Creation: September 2, 2023
*/


#ifndef CHARACTER_HPP               //guards in case hpp file unneccessarily called more than once
#define CHARACTER_HPP

#include <iostream>
using namespace std;
#include <cctype>               //needed for toupper() function

enum Race {NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD};            //enum listing the races. Will later turn races to strings.

class Character {       

private:                        //private variables cannot be altered unless through constructor or setters or getters.
    string name_;
    Race race_;
    int vitality_;
    int armor_;
    int level_;
    bool enemy_;


public:
    Character();            //create default constructor
    Character(string a_name, string A_RACE, int A_VITALITY=0 , int A_ARMOR=0, int A_LEVEL=0, bool a_isEnemy=false);     //create parameterized constructor with default arguments for all but name and race.

    void setName(const string &a_name);             //void setter/mutator function with const reference for name
    string getName() const;                         //string getter/accessor function with const for name

    void setRace(const string &A_RACE);             //setter for race
    string getRace() const;                         //STRING return for race getter

    void setVitality(const int &A_VITALITY);        //setter for vitality
    int getVitality() const;                        //int getter for vitality

    void setArmor(const int &A_ARMOR);              //setter for armor
    int getArmor() const;                           //int getter for armor

    void setLevel(const int &A_LEVEL);              //setter for level
    int getLevel() const;                           //int getter for level

    void setEnemy();                                //setter for enemy with NO PARAMETERS as shown through project specifics
    bool isEnemy() const;                           //boolean getter for enemy.

};


#endif
