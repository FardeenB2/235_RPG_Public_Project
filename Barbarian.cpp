
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

/*- A string representing their main weapon
- A string representing their offhand weapon
- A boolean indicating if they are enraged*/
/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
    Default weapons: "NONE". 
*/
Barbarian::Barbarian()
{
    setName ("NAMELESS");
    isEnemy();
    main_weapon_ = "NONE";
    offhand_weapon_ = "NONE";

}
/**
    Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false
    @param      : The character's main weapon (a const string reference). 
                  String inputs can be in lowercase, but must be converted to uppercase 
                  when setting the variable. Only alphabetical characters are allowed.
                  Default to "NONE"
    @param      : The character's offhand weapon (a const string reference). 
                  String inputs can be in lowercase, but must be converted to uppercase 
                  when setting the variable. Only alphabetical characters are allowed.
                  Default to "NONE"
    @param      : A flag indicating whether the character is enraged. Default to false
    @post       : The private members are set to the values of the corresponding parameters. 
                : If the main and secondary weapons are not provided or invalid, the variables                    are set to "NONE".
*/
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
/**
    @param    : a reference to a string representing the Character's main weapon
    @post     : sets the private member variable to the value of the parameter. 
                Only alphabetical characters are allowed.
                String inputs can be in lowercase, but must be converted to uppercase when 
                setting the variable.
                If the given input is invalid (i.e contains numbers), do nothing and return false
    @return   : true if setting the variable was successful, false otherwise.
**/
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
/**
    @return   : a string of the Character's main weapon
**/
string Barbarian::getMainWeapon() const
{
    return main_weapon_;
}
/**
    @param    : a reference to a string representing the Character's secondary weapon
    @post     : sets the private member variable to the value of the parameter. 
                Only alphabetical characters are allowed.
                String inputs can be in lowercase, but must be converted to uppercase when 
                setting the variable.
              : If the given input is invalid (i.e contains numbers), do nothing and return false
    @return   : true if setting the variable was successful, false otherwise.
**/
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
/**
   @return    : a string of the Character's secondary weapon
**/
string Barbarian::getSecondaryWeapon() const
{
    return offhand_weapon_;
}
/**
  @param      : a reference to a bool
  @post       : sets the private member variable to the value of the parameter.
**/
void Barbarian::setEnrage (const bool& enraged)
{
    enraged_ = enraged;

}
/**
  @return  : a boolean of whether the Character is enraged
**/
bool Barbarian::getEnrage () const
{
    return enraged_;
}
/**
  @post   : sets the enraged variable to the opposite of what it was
**/
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