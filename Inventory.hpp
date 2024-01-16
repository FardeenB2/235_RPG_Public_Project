//PROJECT 7 (Final Project on Binary Search Tree)
//Fardeen Bhuiyan
//December 11, 2023
//CSCI 235 FALL 2023


#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <iostream>
#include <memory>

#include "BinarySearchTree.hpp"
#include "BinaryNode.hpp"
#include "Item.hpp" //needed
#include <algorithm>
#include <vector>


class Inventory : public BinarySearchTree<Item*> {
public:
    Inventory();    

    //Inventory(const T* rootItem) : BinarySearchTree<T>(rootItem) {}     //i replaced & with *

    //Inventory(const BinarySearchTree<T>& tree) : BinarySearchTree<T>(tree) {}

    //virtual ~Inventory() {}     //according to EDdiscussion UTA, destructor not needed. only the default constructor is needed.



    bool addItem(Item* trinket);

    bool removeItem(const std::string& trinket);

    Item* findItem(const std::string& trinket);

    void inorderTrav (void visit(Item*), std::shared_ptr<BinaryNode<Item*>> tree_pointer_node);

    int getTotalGoldValue();
   
    void printInventoryInOrder();

    void printInventory(const bool& ASC, const std::string& order);






};

static int goldValueCounter;

void helperGoldFunctor(Item* trinket);


void helperprintinorder(Item* trinket);




static std::vector<Item*> holdNodesVec;     //this holds all the nodes from the BST

static std::vector<Item*> orderedVec;       //this is the ordered vector for the last function.

static std::string typeParam;           //not really needed, but tells me the parameter type that user inputs to last function

static bool ascend;     //not really needed, but tells me the user's inputted ascend of descend bool for last funciton parameter

void TreeToVector(Item* trinket);       //function that takes the nodes of BST and places into holdNodesVec


//#include "Inventory.cpp"  commented out cuz UTA said to remove. Actually this was the fix that made my project finally compile on gradescope.

#endif // INVENTORY_HPP