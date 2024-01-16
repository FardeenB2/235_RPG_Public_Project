/*
CSCI235 Fall 2023
Project 7 - Trinkets and Baubles
Georgina Woo
Sep 6 2023
Item.hpp declares the Item class along with its private and public members
*/


#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <ctime>
#include <chrono>

enum ItemType 
{
    UNKNOWN,
    WEAPON,
    ARMOR,
    CONSUMABLE
};


class Item {
public:
    
    /*Constructors */
    Item();

    /*
    @post: the quantity for Items of type other than CONSUMABLE is always set to 1
         : default value for negative int arguments is also 1
         : default value for type_ is UNKNOWN
         : names are converted to uppercase, oly alphabetical characters, with dafault value "UNKNOWN"

    */
    Item(const std::string& name, ItemType type = UNKNOWN, int level = 0, int gold_value = 0, int quantity = 1);

   /*
    @return : a string corresponding to the name of the Item
    */
    std::string getName() const;
    /*
    @return : a string corresponding to the Item type
    */
    std::string getType() const;
    /*
    @return : an integer indicating the level of the Item 
    */
    int getLevel() const;
    /*
    @return : an integer indicating the gold value of the Item 
    */
    int getGoldValue() const;
    /*
    @return : an integer indicating the quantity value of the Item 
    */
    int getQuantity() const;
    /*
    @return : an time_t value indicating the time the Item was picked up
    */
    time_t getTimePickedUp() const;

    /*
    @param: a reference to ItemType
    @post: sets the value of type_ to the parameter, with default value UNKNOWN
    */
    void setType(const ItemType& type);
    /*
    @param: a reference to ItemType
    @post:  sets the value of name_ to the parameter, with default value "UNKNOWN"
         :  all input strings are converted to uppercase and numbers are dropped.
         : if no alphabetical characters in in put string, default to "UNKNOWN"
    */
    void setName(const std::string& name);
    /*
    @param: a reference to int indicating the level
    @post: sets the value of level_ to that of the argument if non-negative
    */
    void setLevel(const int& level);
    /*
    @param: a reference to int indicating the gold_value_
    @post: sets the value of gold_value_ to that of the argument if non-negative
    */
    void setGoldValue(const int& gold_value);
    /*
    @param: a reference to int indicating the quantity
    @post: sets the value of quantity_ to the argument if the argument is positive and the type is CONSUMABLE
         :  otherwise, if the argument is positive, sets the quantity to 1 for all other ItemTypes.
    @return: true if the quantity was set, false otherwise
    */
    bool setQuantity(const int& quantity);
    /*
    @param: a reference to int indicating the time the item was picked up
    @post: sets the value of time_picked_up_ to that of the argument
    */
    void setTimePickedUp(const time_t& time_picked_up);
    /*
   @post: sets the value of time_picked_up_ to the current time
    */
    void updateTimePickedUp();

    /*
   @return: true if the Items have the same name, false otherwise
    */
    bool operator==(const Item& other) const;
    /*
   @return: true if the name of this item is lower in alphabetical order than the name of the argument, false otherwise
    */
    bool operator<(const Item& other) const;
    /*
   @return: true if the name of this item is greater in alphabetical order than the name of the argument, false otherwise
    */
    bool operator>(const Item& other) const;
    

private:
    std::string name_;
    ItemType type_;
    int level_;
    int gold_value_;
    int quantity_;
    time_t time_picked_up_;
    
};
#endif // ITEM_HPP