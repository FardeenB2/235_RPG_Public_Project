
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

//The red squiggly underlines are because I haven't used inheritance yet.

/*- A string that represents their school of magic
- A string that represents their weapon
- A boolean indicating if they are able to summon an incarnate*/


/**
  Default constructor.
  Default-initializes all private members. 
  Default character name: "NAMELESS". Booleans are default-initialized to False. 
  Default school of magic and weapon: "NONE". 
*/
Mage::Mage()
{
    school_of_magic_ = "NONE";
    weapon_ = "NONE";
    summon_incarnate_ = false;
    setName ("NAMELESS");
    isEnemy();              //i think this just returns whatever enemy_  is , and since by default in the defautl Character constructor, enemy_ is already false

    

}

/**
  Parameterized constructor.
  @param      : The name of the character (a const string reference)
  @param      : The race of the character (a const string reference)
  @param      : The character's vitality (an integer). Default to 0
  @param      : The character's max armor level (an integer). Default to 0
  @param      : The character's level (an integer). Default to 0
  @param      : A flag indicating whether the character is an enemy. Default to false.
  @param      : The character's school of magic (a const string reference). Valid schools: 
                [ELEMENTAL, NECROMANCY, ILLUSION]. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable. Default to "NONE".
  @param      : The character's choice of weapon (a const string reference). 
                Valid weapons: [WAND, STAFF]
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable. Default to "NONE".
  @param      : A flag indicating whether the character is able to summon an 
                incarnate. Default to false.
  @post       : The private members are set to the values of the corresponding 
                parameters.
                REMEMBER: If the school of magic or weapon is not provided or invalid, the 
                variables should be set to "NONE". 
*/
Mage::Mage(const string& name, const string& race, int vitality, int armor, int level, bool enemy, 
        const string& magic_school, const string& weapon, bool can_incarnate)
{

    setName(name); // checks valid name. in return, setName sets private member name_ to whatever parameter name is.
    setRace(race); // checks valid race

    setVitality (vitality);
    setArmor(armor);
    setLevel(level);
    isEnemy();              //i think this just returns whatever enemy_  is , and since by default in the defautl parameter constructor,  enemy_ is already false     

    /*
    (vitality >= 0) ? vitality_ = vitality: vitality_ = 0;          //if greater than or equal to 0, private member vitality_ = parameter vitality. if less than 0, private member vitality_ = 0.
    (armor >= 0) ? armor_ = armor: armor_ = 0;
    (level >= 0) ? level_ = level: level_ = 0;
    enemy_ = enemy; 
    */

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
/**
    @param  : a reference to a string representing the school of magic
    @post   : sets the private member variable to the value of the parameter. If 
              the provided school of magic is not one of the following: [ELEMENTAL, 
              NECROMANCY, ILLUSION], do nothing and return false.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
    @return  : true if setting the variable was successful, false otherwise.
**/
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
        return false;      //redundant tbh
    }

    else
    {
        return false;          //invalid school name
    }

}

/**
  @return  : the string indicating the character's school of magic
**/
string Mage::getSchool() const
{
    return school_of_magic_;            //return private member variable string
}

/**
    @param  : a reference to a string representing the character's weapon
    @post   : sets the private member variable to the value of the parameter.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
              If the provided weapon is not one of the following: 
              [WAND, STAFF], do nothing and return false.
    @return  : true if setting the variable was successful, false otherwise.
**/
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
/**
  @return  : the string indicating the character's weapon
**/
string Mage::getCastingWeapon() const
{
    return weapon_;
}
/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating whether the character can 
            summon an incarnate
**/
void Mage::setIncarnateSummon(const bool& incarnate)       //can this mage summon an incarnate?
{
    summon_incarnate_ = incarnate;              //iffy. but I think this is what the instructions want.
}
/**
  @return  : the summon-incarnate flag
**/
bool Mage::hasIncarnateSummon() const
{
    return summon_incarnate_;       //returns whatever the private member is (true or false)
}


//ITS NOW A 0/80 because you added & to bool incarnate for setIncarnateSummon in hpp and cpp for mage class.