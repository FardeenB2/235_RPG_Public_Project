
/*
File Title: Mage.cpp
email: fardeen.bhuiyan70@myhunter.cuny.edu
Author: Fardeen Bhuiyan
Brief Description: This program uses Project 1's fantasy character cpp and hpp, and inherits from that so that we have multiple subclasses of warriors
that each have their own unique tools and functions and attributes.
Date of Submission: September 22, 2023
*/




#include "Mage.hpp"

#include "Character.hpp"



Mage::Mage()
{
    school_of_magic_ = "NONE";
    weapon_ = "NONE";
    summon_incarnate_ = false;
    setName ("NAMELESS");
    isEnemy();              

    

}


Mage::Mage(const string& name, const string& race, int vitality, int armor, int level, bool enemy, 
        const string& magic_school, const string& weapon, bool can_incarnate)
{

    setName(name); // checks valid name. in return, setName sets private member name_ to whatever parameter name is.
    setRace(race); // checks valid race

    setVitality (vitality);
    setArmor(armor);
    setLevel(level);
    isEnemy();                  



    if (setSchool(magic_school) == false)  //checks the boolean setSchool function if school name is false
    {
        school_of_magic_ = "NONE";
    }
    else
    {
        setSchool(magic_school);        //if school is true, set private member to parameter using setSchool function
    }

    if (setCastingWeapon(weapon) == false)
    {
        weapon_ = "NONE";
    }
    else
    {
        setCastingWeapon(weapon);
    }
    
    summon_incarnate_ = can_incarnate;      //directly sets private member summon_incarnate to parameter can_incarnate. default should already be false in hpp

}

bool Mage::setSchool(const string& magic_school)
{
    string title = magic_school;          //easier to type
    string newTitle = "";           //placeholder for new string.
    char upperChar;                 //the converted letter to new uppercase letter.

    for (int i = 0; i < title.length(); i++)            //loop through string
    {
        //if (isalpha(title[i]))      //check if only letters. NOTE: if you manually set this to isalpha(title[i])==true, gradescope gets an ERROR. Maybe a version issue
        
            upperChar = toupper(title[i]);      //convert the letter to uppercase using toupper() function
            newTitle += upperChar;               //formulate new title with uppercase letters only.
        
    }

    if (newTitle == "ELEMENTAL")            //name works
    {
        school_of_magic_ = newTitle;        //sets the private member variable

        return true;
    }

    else if (newTitle == "NECROMANCY")
    {
        school_of_magic_ = newTitle;

        return true;
    }

    else if (newTitle == "ILLUSION")
    {
        school_of_magic_ = newTitle;

        return true;
    }

    else if (newTitle.empty())         //if there are no letters at all            //you could also, loop through title.length again and find if there is no isalpha letters at all, but that takes longer.
    {
        return false;      //redundant to be honest
    }

    else
    {
        return false;          //invalid school name
    }

}


string Mage::getSchool() const
{
    return school_of_magic_;            //return private member variable string
}


bool Mage::setCastingWeapon(const string& weapon)
{
    string title = weapon;          //easier to type
    string newTitle = "";           //placeholder for new string.
    char upperChar;                 //the converted letter to new uppercase letter.

    for (int i = 0; i < title.length(); i++)            //loop through string
    {
        //if (isalpha(title[i]))      //check if only letters. NOTE: if you manually set this to isalpha(title[i])==true, gradescope gets an ERROR. Maybe a version issue
        
            upperChar = toupper(title[i]);      //convert the letter to uppercase using toupper() function
            newTitle += upperChar;               //formulate new title with uppercase letters only.
        
    }

    if (newTitle == "WAND")            //name works
    {
        
        weapon_ = newTitle;
        return true;
    }

    else if (newTitle == "STAFF")
    {
        
        weapon_ = newTitle;
        return true;

    }


    else if (newTitle.empty())         //if there are no letters at all            //you could also, loop through title.length again and find if there is no isalpha letters at all, but that takes longer.
    {
        return false;      //redundant tbh
    }

    else
    {
        return false;          //invalid weapon name
    }
}

string Mage::getCastingWeapon() const
{
    return weapon_;
}

void Mage::setIncarnateSummon(const bool& incarnate)       //can this mage summon an incarnate?
{
    summon_incarnate_ = incarnate;              //iffy. but I think this is what the instructions want.
}

bool Mage::hasIncarnateSummon() const
{
    return summon_incarnate_;       //returns whatever the private member is (true or false)
}

