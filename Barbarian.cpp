
/*
File Title: Barbarian.cpp
email: fardeen.bhuiyan70@myhunter.cuny.edu
Author: Fardeen Bhuiyan
Brief Description: This program uses Project 1's fantasy character cpp and hpp, and inherits from that so that we have multiple subclasses of warriors
that each have their own unique tools and functions and attributes.
Date of Submission: September 22, 2023
*/
#include "Barbarian.hpp"

#include "Character.hpp"


Barbarian::Barbarian()
{
    setName ("NAMELESS");
    isEnemy();
    main_weapon_ = "NONE";
    offhand_weapon_ = "NONE";

}

Barbarian::Barbarian (const string& name, const string& race, int vitality, int armor, int level, bool enemy, 
        const string& main_weapon, const string& offhand_weapon, bool enraged)
{

    setName(name); // checks valid name. in return, setName sets private member name_ to whatever parameter name is.
    setRace(race); // checks valid race

    setVitality (vitality);
    setArmor(armor);
    setLevel(level);
    isEnemy(); 

    if (setMainWeapon(main_weapon) == false)
    {
        main_weapon_ = "NONE";
    }
    else
    {
        setMainWeapon(main_weapon);
    }

    if (setSecondaryWeapon(offhand_weapon) == false)
    {
        offhand_weapon_ = "NONE";
    }

    else
    {
        setSecondaryWeapon(offhand_weapon);
    }

    enraged_ = enraged;     //should already default to false in accoradance to default parameters.


}

bool Barbarian::setMainWeapon (const string& main_weapon)
{
    string title = main_weapon;          //easier to type
    string newTitle = "";           //placeholder for new string.
    char upperChar;                 //the converted letter to new uppercase letter.

    int nonLetterCount = 0;

    for (int i = 0; i < title.length(); i++)            //loop through string
    {
        if (isalpha(title[i]))      //check if only letters. NOTE: if you manually set this to isalpha(title[i])==true, gradescope gets an ERROR. Maybe a version issue
        {
            upperChar = toupper(title[i]);      //convert the letter to uppercase using toupper() function
            newTitle += upperChar;               //formulate new title with uppercase letters only.
        }
        else
        {
            nonLetterCount ++;
        }
    }

    if (nonLetterCount > 0)             //the input was invalid
    {
        return false;
    }

   /*                   UNNEEDED
    if (!newTitle.empty())         //if there are any letters at all 
    {
        main_weapon_ = newTitle;                 //this takes into consideration 
    }
    */

    else
    {
        main_weapon_ = newTitle;
        return true;                //looping through the input was successful
    }


}

string Barbarian::getMainWeapon() const
{
    return main_weapon_;
}

bool Barbarian::setSecondaryWeapon (const string& offhand_weapon)
{
    string title = offhand_weapon;          //easier to type
    string newTitle = "";           //placeholder for new string.
    char upperChar;                 //the converted letter to new uppercase letter.

    int nonLetterCount = 0;

    for (int i = 0; i < title.length(); i++)            //loop through string
    {
        if (isalpha(title[i]))      //check if only letters. NOTE: if you manually set this to isalpha(title[i])==true, gradescope gets an ERROR. Maybe a version issue
        {
            upperChar = toupper(title[i]);      //convert the letter to uppercase using toupper() function
            newTitle += upperChar;               //formulate new title with uppercase letters only.
        }
        else
        {
            nonLetterCount ++;
        }
    }

    if (nonLetterCount > 0)             //the input was invalid
    {
        return false;
    }

   /*                   UNNEEDED
    if (!newTitle.empty())         //if there are any letters at all 
    {
        main_weapon_ = newTitle;                 //this takes into consideration 
    }
    */

    else
    {
        offhand_weapon_ = newTitle;
        return true;                //looping through the input was successful
    }

}

string Barbarian::getSecondaryWeapon() const
{
    return offhand_weapon_;
}

void Barbarian::setEnrage (const bool& enraged)
{
    enraged_ = enraged;

}

bool Barbarian::getEnrage () const
{
    return enraged_;
}

void Barbarian::toggleEnrage()
{
    if (enraged_)           //if enraged is true
    {
        enraged_ = false;
    }
    else
    {
        enraged_ = true;
    }

}