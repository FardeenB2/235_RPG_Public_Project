/*
File Title: Character.cpp
Author: Fardeen Bhuiyan
Brief Description: This program creates a Fantasy Character class that contains the data of
name, race, vitality, armor, and level of the character and whether they are an enemy or not.
It can initialize these variables and alter them anytime.
Date of original Creation: September 2, 2023
*/

#include "Character.hpp"



Character::Character()    //default constructor.
          
{

    name_ = "NAMELESS";
    race_ = NONE;           
    vitality_ = 0;
    armor_ = 0;
    level_ = 0;
    enemy_ = false;
    /*
      Default constructor.
      Default-initializes all private members. 
      Default character name: "NAMELESS". 
      Booleans are default-initialized to False. 
      Default enum value: NONE. 
      Default Vitality, Max Armor, and Level: 0.
   */
}

Character::Character(string a_name, string A_RACE, int A_VITALITY , int A_ARMOR, int A_LEVEL, bool a_isEnemy){
    setName(a_name); 
    setRace(A_RACE);            //setters aren't preferred to be called in parameter constructors, but these specific variables require more alteration

//note to self: the reason we do this is because even though our default parameter in constructor already sets vitality, armor, and level to 0,
//if the user sets these things to negative numbers first, the default parameter will Not come into play.
//and we can't call our setter function to change these values because that kind of reverses the purpose of having a paramterized constructor. 



    if (A_VITALITY < 0)                 
    {
        vitality_ = 0;      //default. As shown per instructions, no numbers can be ignored considering the default is always 0 in constructor.
    }
    else
    {
        vitality_ = A_VITALITY;             //setters aren't convetionally called in constructors, so we directly change the private variable to the parameter here.                      
    }

    if (A_ARMOR < 0)
    {
        armor_ = 0;      //default
    }
    else
    {
        armor_ = A_ARMOR;       
    }
    
    if (A_LEVEL < 0)
    {
        level_ = 0;      //default. 
    }
    else
    {
        level_ = A_LEVEL;
    }
    
    enemy_ = a_isEnemy;

  /*
  Parameterized constructor.
  @param      : The name of the character (a string in UPPERCASE)
  @param      : The race of the character (a string)
  @param      : The character's vitality (a non-negative integer) , with default  
                value 0
  @param      : The character's max armor level (a non-negative integer), with 
                default value 0
  @param      : The character's level (non-negative integer), with default value 0
  @param      : A flag indicating whether the character is an enemy, with default 
                value false
  @post       : The private members are set to the values of the corresponding 
                parameters.
  */

}                           


void Character::setName(const string &a_name)           
{
    string title = a_name;          //easier to type
    string newTitle = "";           //placeholder for new string.
    char upperChar;                 //the converted letter to new uppercase letter.

    for (int i = 0; i < title.length(); i++)            //loop through string
    {
        if (isalpha(title[i]))      //check if only letters. NOTE: if you manually set this to isalpha(title[i])==true, gradescope gets an ERROR. Maybe a version issue
        {
            upperChar = toupper(title[i]);      //convert the letter to uppercase using toupper() function
            newTitle += upperChar;               //formulate new title with uppercase letters only.
        }
    }

    if (newTitle.empty())         //if there are no letters at all            //you could also, loop through title.length again and find if there is no isalpha letters at all, but that takes longer.
    {
        name_ = "NAMELESS";
    }

    else
    {
        name_ = newTitle;                            //this is the new character title. Sets private member variable to this name.
    }

       /*
            @param  : the name of the Character
            @post   : sets the Character's title to the value of the parameter, 
                      in UPPERCASE. Only alphabetical characters are allowed. 
                      For example, attempting to create a character named 
                      "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
                    : If the given parameter does not have any valid alphabetical
                      characters, the character's name should be set to "NAMELESS".
        */
}

string Character::getName() const
{
    return name_;            //return private member variable

    /*
      @return : the name of the Character
    */
}

void Character::setRace(const string &A_RACE)   
{
    if (A_RACE == "NONE")                   //so if the test.cpp tells us a race string, we find the equivalent enum selection, and set private variable race_ to that enum.
    {
        race_ = NONE;
    } 
    else if (A_RACE == "HUMAN") 
    {
        race_  = HUMAN;
    }
    else if (A_RACE == "ELF") 
    {
        race_  = ELF;
    }
    else if (A_RACE == "DWARF")
    {
        race_  = DWARF;
    }
    else if (A_RACE == "LIZARD")
    {
        race_  = LIZARD;
    }
    else if (A_RACE == "UNDEAD")
    {
        race_  = UNDEAD;
    }

    else
    {
        race_  = NONE;              //The first if (A_RACE == "NONE") is not needed if we have this else statement, but not too big of an issue.
    }

    /*
       @param  : the race of the Character (a string)
       @post   : sets the Character's race to the value of the parameter.
                 If the given race was invalid, set race_ to NONE.
    */
}

string Character::getRace() const
{
   if (race_  == NONE)              //now we look at what enum selection we set the race_ to (because of our setter), and return a string version of that enum
   {
        return "NONE";
   }
   else if (race_  == HUMAN)
   {
        return "HUMAN";
   }
    else if (race_  == ELF)
   {
        return "ELF";
   }
    else if (race_  == DWARF)
   {
        return "DWARF";
   }
    else if (race_ == LIZARD)
   {
        return "LIZARD";
   }
    else if (race_  == UNDEAD)
   {
        return "UNDEAD";
   }
   
   else
   {
       return "NONE";
   }

   /*
      @return : the race of the Character (a string)
   */
}

void Character::setVitality(const int &A_VITALITY)
{

    if (A_VITALITY >= 0)            //as per instructions, we only care about 0 and above. Ignore negative numbers.
    {
        vitality_ = A_VITALITY;
    }
 
    /*
    @param  : an integer vitality
    @pre    : vitality >= 0 : Characters cannot have negative health
    @post   : sets the vitality private member to the value of the parameter
              if vitality is negative, do nothing.
    */  
    
}

int Character::getVitality() const
{
    return vitality_;

    /*
      @return : the value stored in vitality_
    */
}

void Character::setArmor(const int &A_ARMOR)
{
    
    if (A_ARMOR >= 0)
    {
        armor_ = A_ARMOR;       //fine  .if negative, don't change. reason being, the default parameter in the paramet constructor should set it to 0 first. But if you call the setter and the number is negative, you don't want the level to turn to 0. You want that negative numebr call to be ignored
    }
  
  /*
    @param  : an integer armor level
    @pre    : armor >= 0 : Characters cannot have negative armor
    @post   : sets the armor private member to the value of the parameter
              if armor is negative, do nothing.
  */

}

int Character::getArmor() const
{
    return armor_;
    /*
      @return : the value stored in armor_
    */
}


void Character::setLevel(const int &A_LEVEL)
{
    
    if (A_LEVEL >= 0)
    {
        level_ = A_LEVEL;
    }
   
    /*
    @param  : an integer level
    @pre    : level >= 0 : Characters cannot have a negative
    @post   : sets the level private member to the value of the parameter
              if level is negative, do nothing.
    */

}

int Character::getLevel() const
{
    return level_;

    /*
      @return : the value stored in level_
    */
}


void Character::setEnemy()        //The specific setter can be called later if needed. Constructors can only be used once. after that, setters are called.
{  
                        
   enemy_ = true;       //default parameter in constructor already sets it to false. Any setter call should set it to true because instructions say so.
  /*
   @post   : sets the enemy flag to true
  */
}   

bool Character::isEnemy() const
{
   return enemy_;           //if you return enemy_, if enemy_ is true, it will return true. return false if false.
                            //this getter is  like every other getter before. return private variable.
    /*
    @return true if the character is an enemy, false otherwise

    Note: this is an accessor function and must follow the same convention as all accessor  
          functions even if it is not called getEnemy
    */
}
