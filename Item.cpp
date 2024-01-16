/*
CSCI235 Fall 2023
Project 7 - Trinkets and Baubles
Georgina Woo
Sep 6 2023
Item.cpp declares the Item class and implements its private and public members
*/
#include "Item.hpp"

/*Constructors */

Item::Item(): type_{UNKNOWN}, name_{"UNKNOWN"}, level_{1}, gold_value_{1},quantity_{1}
{
    updateTimePickedUp();
}

/*
    @post: the quantity for Items of type other than CONSUMABLE is always set to 1
         : default value for negative int arguments is also 1
         : default value for type_ is UNKNOWN
         : names are converted to uppercase, oly alphabetical characters, with dafault value "UNKNOWN"

*/
Item::Item(const std::string& name, ItemType type, int level, int gold_value, int quantity)
{
    setName(name);
    setType(type);
    level_ = (level > 0) ? level : 1;
    gold_value_ = (gold_value > 0) ? gold_value : 1;
    if (!setQuantity(quantity)) quantity_ = 1;
    updateTimePickedUp();
}

// Getters

/*
    @return : a string corresponding to the Item type
*/
std::string Item::getType() const 
{
    switch (type_) 
    {
        case WEAPON:
            return "WEAPON";
        case ARMOR:
            return "ARMOR";
        case CONSUMABLE:
            return "CONSUMABLE";
        default:
            return "UNKNOWN";
    }
}

/*
    @return : a string corresponding to the name of the Item
*/
std::string Item::getName() const 
{
    return name_;
}

/*
    @return : an integer indicating the level of the Item 
*/
int Item::getLevel() const 
{
    return level_;
}

/*
    @return : an integer indicating the gold value of the Item 
*/
int Item::getGoldValue() const 
{
    return gold_value_;
}

/*
    @return : an integer indicating the quantity value of the Item 
*/
int Item::getQuantity() const 
{
    return quantity_;
}

/*
    @return : an time_t value indicating the time the Item was picked up
*/
time_t Item::getTimePickedUp() const 
{
    return time_picked_up_;
}



// Setters

/*
    @param: a reference to ItemType
    @post: sets the value of type_ to the parameter, with default value UNKNOWN
*/
void Item::setType(const ItemType& type) 
{
    if (type == WEAPON || type == ARMOR || type == CONSUMABLE) 
    {
        type_ = type;
    }
    else 
    {
        type_ = UNKNOWN;
    }
}


/*
    @param: a reference to ItemType
    @post:  sets the value of name_ to the parameter, with default value "UNKNOWN"
         :  all input strings are converted to uppercase and numbers are dropped.
         : if no alphabetical characters in in put string, default to "UNKNOWN"
*/
void Item::setName(const std::string& name) 
{
    std::string res = "";
    for(char c : name)
    {
        if(isalpha(c) || c == ' ')
        {
            res += toupper(c) ;
        }
    }
    if (res.empty()) 
    {
        name_ = "UNKNOWN";
    }
    else
    {
        name_ = res;
    }
}


/*
    @param: a reference to int indicating the level
    @post: sets the value of level_ to that of the argument if non-negative
*/
void Item::setLevel(const int& level) 
{
    if (level>=1)
    {
        level_ = level;
    }
}

/*
    @param: a reference to int indicating the gold_value_
    @post: sets the value of gold_value_ to that of the argument if non-negative
*/
void Item::setGoldValue(const int& gold_value) 
{
    if(gold_value>=1)
    {
        gold_value_ = gold_value;
    }
}


/*
    @param: a reference to int indicating the quantity
    @post: sets the value of quantity_ to the argument if the argument is positive and the type is CONSUMABLE
         :  otherwise, if the argument is positive, sets the quantity to 1 for all other ItemTypes.
    @return: true if the quantity was set, false otherwise
*/
bool Item::setQuantity(const int& quantity) 
{
    // Only continue processing for valid quantities
    if(quantity>=1)
    {
        // if the quantity is more than 1, it's only valid if its a consumable. Other types of items only get to have a quantity of 1 
        if(type_ == CONSUMABLE)
        {
            quantity_ = quantity;
        }
        else
        {
            quantity_ = 1;
        }
        return true;
    }
    else
    {
        return false;
    }
}


/*
    @param: a reference to int indicating the time the item was picked up
    @post: sets the value of time_picked_up_ to that of the argument
*/
void Item::setTimePickedUp(const time_t& time_picked_up)
{
    time_picked_up_ = time_picked_up;
}

/*
   @post: sets the value of time_picked_up_ to the current time
*/
void Item::updateTimePickedUp() 
{
    using namespace std::chrono;
    time_picked_up_ = duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
}


/*
   @return: true if the Items have the same name, false otherwise
*/
bool Item::operator==(const Item& other) const 
{
    return this->getName() == other.getName();
}
/*
   @return: true if the name of this item is lower in alphabetical order than the name of the argument, false otherwise
*/
bool Item::operator<(const Item& other) const 
{
    return name_ < other.getName();
}

/*
   @return: true if the name of this item is greater in alphabetical order than the name of the argument, false otherwise
*/
bool Item::operator>(const Item& other) const 
{
    return name_ > other.getName();
}
