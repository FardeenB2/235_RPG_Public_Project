/*
File Title: Scoundrel.cpp
email: fardeen.bhuiyan70@myhunter.cuny.edu
Author: Fardeen Bhuiyan
Brief Description: This program uses Project 1's fantasy character cpp and hpp, and inherits from that so that we have multiple subclasses of warriors
that each have their own unique tools and functions and attributes.
Date of Submission: September 22, 2023
*/
#include "Scoundrel.hpp"

#include "Character.hpp"
/*- A dagger
- A string that represents their Faction
- A boolean indicating if they have a disguise*/

/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default dagger: WOOD. Default faction: "NONE". 
*/

Scoundrel::Scoundrel() : Character()
{
    dagger_ = WOOD;
    faction_ = "NONE";
    disguise_ = false;
}




/**
    Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false.
    @param      : The character's dagger type (a const string reference).
                  String inputs can be in lowercase, but must be converted to 
                  uppercase when setting the dagger enum. Default to WOOD
    @param      : The character's Faction (a const string reference). 
                  Valid Factions: [CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
                  String inputs can be in lowercase, but must be converted to 
                  uppercase when setting the variable. Default to "NONE"
    @param      : A flag indicating whether the character has a disguise. Default to false
    @post       : The private members are set to the values of the corresponding 
                  parameters.
                 If the dagger type is not provided or invalid, the variable should 
                  be set to WOOD. 
                 If the Faction is not provided or invalid, the variable should be 
                  set to "NONE". 
*/

Scoundrel::Scoundrel(const string& name, const string& race, int vitality, int armor, int level, bool enemy, const string& dagger, const string& faction, bool disguise) : Character(name, race, vitality, armor, level, enemy)
{
    setDagger(dagger);

    if (setFaction(faction) == false)
    {
        faction_ = "NONE";
    }
    else
    {
        setFaction(faction);
    }

    disguise_ = disguise;       //default should already be false in hpp parameter constructor


}
/**
   @param     : a reference to a string representing the dagger type
   @post      : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the dagger type is not valid (i.e, is one of the following: 
                [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]), 
                the variable should be set to WOOD. 
**/
void Scoundrel::setDagger(const string& dagger)
{

    string title = dagger;          //easier to type
    string newTitle = "";           //placeholder for new string.
    char upperChar;                 //the converted letter to new uppercase letter.

    for (int i = 0; i < title.length(); i++)            //loop through string
    {
        //if (isalpha(title[i]))      //check if only letters. NOTE: if you manually set this to isalpha(title[i])==true, gradescope gets an ERROR. Maybe a version issue
        
            upperChar = toupper(title[i]);      //convert the letter to uppercase using toupper() function
            newTitle += upperChar;               //formulate new title with uppercase letters only.
        
    }

    if (newTitle == "WOOD")            //name works
    {
        
        dagger_ = WOOD;        //sets the private member variable
    }

    else if (newTitle == "BRONZE")
    {
        
        dagger_ = BRONZE;
    }

    else if (newTitle == "IRON")
    {
        
        dagger_  = IRON;
    }

    else if (newTitle == "STEEL")
    {
        
        dagger_  = STEEL;
    }
    else if (newTitle == "MITHRIL")
    {
        
        dagger_ = MITHRIL;
    }
    else if (newTitle == "ADAMANT")
    {
        
        dagger_  = ADAMANT;
    }
    else if (newTitle == "RUNE")
    {
        
        dagger_ = RUNE;
    }

    else if (newTitle.empty())         //if there are no letters at all            //you could also, loop through title.length again and find if there is no isalpha letters at all, but that takes longer.
    {
        dagger_ = WOOD;        //redundant to be honest
    }

    else
    {
        dagger_ = WOOD;          //invalid school name
    }

}
/**
  @return     : the string indicating the character's dagger type
**/
string Scoundrel::getDagger() const
{
    string bladeType = "WOOD";

    if (dagger_ == WOOD)            //if the private variable enum equals this
    {
        
        bladeType = "WOOD"; 
        return bladeType;       //return string

    }

    else if (dagger_ == BRONZE)
    {
        
        bladeType = "BRONZE";
        return bladeType;
    }

    else if (dagger_  == IRON)
    {
        
        bladeType = "IRON";
        return bladeType;
    }

    else if (dagger_  == STEEL)
    {
        
        bladeType = "STEEL";
        return bladeType;
    }
    else if (dagger_  == MITHRIL)
    {
        
        bladeType = "MITHRIL";
        return bladeType;
    }
    else if (dagger_  == ADAMANT)
    {
        
        bladeType = "ADAMANT";
        return bladeType;
    }
    else if (dagger_  == RUNE)
    {
        
        bladeType= "RUNE";
        return bladeType;
    }

    return bladeType;

}
/**
    @param    : a reference to a string representing the character's Faction
    @post     : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the provided faction is not one of the following: 
               [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], 
               do nothing and return false.
    @return   : true if setting the variable was successful, false otherwise.
**/
bool Scoundrel::setFaction (const string& faction)
{
    string title = faction;          //easier to type
    string newTitle = "";           //placeholder for new string.
    char upperChar;                 //the converted letter to new uppercase letter.

    for (int i = 0; i < title.length(); i++)            //loop through string
    {
        //if (isalpha(title[i]))      //check if only letters. NOTE: if you manually set this to isalpha(title[i])==true, gradescope gets an ERROR. Maybe a version issue
        
            upperChar = toupper(title[i]);      //convert the letter to uppercase using toupper() function
            newTitle += upperChar;               //formulate new title with uppercase letters only.
        
    }

    if (newTitle == "NONE")            //name works
    {
        
        faction_ = newTitle;        //sets the private member variable
        return true;
    }

    else if (newTitle == "CUTPURSE")
    {
        
        faction_ = newTitle;
        return true;
    }

    else if (newTitle == "SHADOWBLADE")
    {
        
        faction_ = newTitle;
        return true;
    }

    else if (newTitle == "SILVERTONGUE")
    {
        
        faction_ = newTitle;
        return true;
    }
   
    else if (newTitle.empty())         //if there are no letters at all            //you could also, loop through title.length again and find if there is no isalpha letters at all, but that takes longer.
    {
        return false;        //redundant to be honest
    }

    else
    {
        return false;          //invalid school name
    }



}

/**
  @return  : the string indicating the character's Faction
**/
string Scoundrel::getFaction() const
{
    return faction_;

}
/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating whether the character has a disguise
**/
void Scoundrel::setDisguise(const bool& disguise)
{
    disguise_ = disguise;
    
}
/**
  @return  : the disguise flag
**/
bool Scoundrel::hasDisguise() const
{
    return disguise_;

}