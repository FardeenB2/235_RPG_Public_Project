#include <iostream>
#include <ctime>
#include "Inventory.hpp"


Inventory::Inventory():BinarySearchTree<Item*>() {}


bool Inventory::addItem(Item* trinket)
{

    if (trinket == nullptr)
    {
        return false;
    }
    
    else if ( (trinket->getType() == "UNKNOWN" || trinket->getType() == "WEAPON" || trinket->getType() == "ARMOR") && findItem(trinket->getName()) == nullptr)
    {
        add(trinket);   //it should add alphabetically to the binary tree.
        return true;    //item trinket is successfully added
    }
          //the project specifications don't seem specific enough. the above code doesn't SEEM needed.

    else if (trinket->getType() ==  "CONSUMABLE")
    {
        if (findItem(trinket->getName()) != nullptr)    //if the item already exists in the inventory
        {
            Item* existingTrinket;
            existingTrinket= findItem(trinket->getName());

            existingTrinket->setQuantity( trinket->getQuantity() + existingTrinket->getQuantity() ); //add the quantity of the existing amount with the new quantity from the parameter
           //trinket is the new stuff. existingTrinket is the already existing stuff.
            
            existingTrinket->updateTimePickedUp();  //this looks right
        }

        else
        {
            add(trinket);
        }

        return true;
    }


    //use the sort function method from project 6, and compare the alphabetical parts. it seems as though every other part is faster to complete than add
    //NOOOOO, use the operator functions defined in the item.hpp
    //actually that is also not needed. the binarytree add function does alphabetical already

    return false;
}

bool Inventory::removeItem(const std::string& trinket)
{
//to understand this better, finditem() was the function implemented first

    Item trinketObject;
    trinketObject.setName(trinket); //now we have an object to compare with

    Item* save;

    if (getPointerTo(&trinketObject) != nullptr)    //you gotta FIRST, ALWAYS FIRST, check if the pointer is nullptr. or get segmentation fault.
    {
        save = getPointerTo(&trinketObject)->getItem(); //retrieve and store that ACTUAL item from node from BST into save.
    }
    else
    {
        return false;
    }

    if (findItem(trinket) != nullptr)   //if the object exists in BST
    {

        if (save->getType() == "CONSUMABLE")
        {
            if (save->getQuantity() == 1)
            {
                return remove(save);  //if the existing quantity is already 1, just remove it altogether
            }

            else
            {
                save->setQuantity( save->getQuantity()-1 ); //take consumable's existing quantity and decrement        
            }
        }
        
        else if (save->getType() == "UNKNOWN" || save->getType() ==  "WEAPON" || save->getType()  == "ARMOR")
        {
            return remove(save);

        }
                
    }

    return false;



}



Item* Inventory::findItem(const std::string& trinket)
{
    Item trinketObject;
    trinketObject.setName(trinket);

    Item* save;

    if (contains(&trinketObject))
    {
        save = getPointerTo(&trinketObject)->getItem();

        if (save != nullptr)
        {
            return save;     //F Doubt
        }
    }   //Get the pointer to item that is found when traversing the BST. We do this by getting the shared_ptr from getPointerTo which also got its value from findNode() function.
        //To access the object item*, we gotta call getItem() using ->, just like with normal pointers.


        
    return nullptr;
    


//^The above conditional works because it contains uses findnode which uses operator from item.cpp which uses names only.
//The above comment works if we were comparing the exact same item (with all its type, name, quantity, etc.) properties with the parameter. 
//But the parameter is a string, so it relies on only name or type. contains(trinketObject) compares everything: the parameter name, the undisclosed type, undisclosed quantity, etc.
//even isolating setName won't work since the other properties are still being compared to find perfect equality.

}

void helperGoldFunctor(Item* trinket)
{
    if (trinket->getType() == "CONSUMABLE")
    {
        goldValueCounter += trinket->getGoldValue() * trinket->getQuantity();   //calculates the total gold in an item.

    }

    else
    {
        goldValueCounter += trinket->getGoldValue();    //if the item is not stackable
    }


}

//This below function is derived from Professor Ligorio's BST_Imp slide
void Inventory::inorderTrav (void visit(Item*), std::shared_ptr<BinaryNode<Item*>> tree_pointer_node)
{
    if (tree_pointer_node != nullptr)   //if it is nullptr, we reached the end of the tree traversing
    {
        //recursive Calls to this function itself
        inorderTrav(visit, tree_pointer_node->getLeftChildPtr());   //check the left node and utilize whatever function for the node
        Item* the_item = tree_pointer_node->getItem(); visit(the_item); //get the current node information utilizing funciton
        inorderTrav(visit, tree_pointer_node->getRightChildPtr());  //check the right node and utilize whatever function for the node 
    }  

}  

int Inventory::getTotalGoldValue()
{
    goldValueCounter = 0;       //since this is a static variable outside of inventory class, it can be accessed as long as you include inventory.hpp
    inorderTrav(helperGoldFunctor, getRoot());  //use helperGoldFunctor to get the total gold of all the items

    return goldValueCounter;

}


void helperprintinorder(Item* trinket)
{
    std::string name = trinket->getName();
    std::string type = trinket->getType();
    int level = trinket->getLevel();
    int value = trinket->getGoldValue();
    int quantity = trinket->getQuantity();

    if (type != "CONSUMABLE")
    {
        std::cout << name <<" (" << type << ")\n" <<
        "Level: " << level << "\nValue: " << value << "\n\n";

    }

    else
    {
        std::cout << name <<" (" << type << ")\n" <<
        "Level: " << level << "\nValue: " << value << "\nQuantity: " << quantity <<"\n\n";

    }

}


void Inventory::printInventoryInOrder()
{
    inorderTrav(helperprintinorder, getRoot());

}




void TreeToVector(Item* trinket)
{
    holdNodesVec.push_back(trinket);
    //this should put all node's item* inside this vector 
    //when we call inorderTrav to traverse with this as a functor.
}



void Inventory::printInventory(const bool& ASC, const std::string& order)
{
    ascend = ASC;

    typeParam = order;


    orderedVec.clear();
    holdNodesVec.clear();       //make sure these are clear first

    inorderTrav(TreeToVector, getRoot());   //TreeToVector functor should now have all the values of the BST in it, through traversing

    if (ascend)
    {   //these sort to check previous vector value with next vector value 
        if (typeParam == "NAME")
        {
            std::sort(holdNodesVec.begin(), holdNodesVec.end(), //Compares the left element with the right in vector.
            [](const Item* left, const Item* right)
            {
                return left->getName() < right->getName();      //if left element's level is less than right, then return. so it becomes ascending vector.
            }
            );

        }

        else if (typeParam == "TYPE")
        {

            std::sort(holdNodesVec.begin(), holdNodesVec.end(), //Compares the left element with the right in vector.
            [](const Item* left, const Item* right)
            {
                return left->getType() < right->getType();      //if left element's level is less than right, then return. so it becomes ascending vector.
            }
            );

        }

        else if (typeParam == "LEVEL")
        {

            std::sort(holdNodesVec.begin(), holdNodesVec.end(), //Compares the left element with the right in vector.
            [](const Item* left, const Item* right)
            {
                return left->getLevel() < right->getLevel();      //if left element's level is less than right, then return. so it becomes ascending vector.
            }
            );

        }

        else if (typeParam == "VALUE")
        {

            std::sort(holdNodesVec.begin(), holdNodesVec.end(), //Compares the left element with the right in vector.
            [](const Item* left, const Item* right)
            {
                return left->getGoldValue() < right->getGoldValue();      //if left element's level is less than right, then return. so it becomes ascending vector.
            }
            );

        }

        else if (typeParam == "TIME")
        {

            std::sort(holdNodesVec.begin(), holdNodesVec.end(), //Compares the left element with the right in vector.
            [](const Item* left, const Item* right)
            {
                return left->getTimePickedUp() < right->getTimePickedUp();      //if left element's level is less than right, then return. so it becomes ascending vector.
            }
            );

        }

        
    }

    else
    {

        if (typeParam == "NAME")
        {
            std::sort(holdNodesVec.begin(), holdNodesVec.end(), //Compares the left element with the right in vector.
            [](const Item* left, const Item* right)
            {
                return left->getName() > right->getName();      //if left element's level is less than right, then return. so it becomes ascending vector.
            }
            );


        }

        if (typeParam == "TYPE")
        {

            std::sort(holdNodesVec.begin(), holdNodesVec.end(), //Compares the left element with the right in vector.
            [](const Item* left, const Item* right)
            {
                return left->getType() > right->getType();      //if left element's level is less than right, then return. so it becomes ascending vector.
            }
            );



        }

        else if (typeParam == "LEVEL")
        {

            std::sort(holdNodesVec.begin(), holdNodesVec.end(), //Compares the left element with the right in vector.
            [](const Item* left, const Item* right)
            {
                return left->getLevel() > right->getLevel();      //if left element's level is less than right, then return. so it becomes ascending vector.
            }
            );

        }

        else if (typeParam == "VALUE")
        {

            std::sort(holdNodesVec.begin(), holdNodesVec.end(), //Compares the left element with the right in vector.
            [](const Item* left, const Item* right)
            {
                return left->getGoldValue() > right->getGoldValue();      //if left element's level is less than right, then return. so it becomes ascending vector.
            }
            );


        }

        else if (typeParam == "TIME")
        {

            std::sort(holdNodesVec.begin(), holdNodesVec.end(), //Compares the left element with the right in vector.
            [](const Item* left, const Item* right)
            {
                return left->getTimePickedUp() > right->getTimePickedUp();      //if left element's level is less than right, then return. so it becomes ascending vector.
            }
            );

        }

    }

    for (int x=0; x < holdNodesVec.size(); x++)     //not really needed actually
    {
        orderedVec.push_back(holdNodesVec[x]);       //new vector with ordered values left to right according to ascending or descending.

    }
    

    std::string name;       //Easier to print out these variables
    std::string type;
    int level;
    int value;
    int quantity;

    for (int a=0; a < orderedVec.size(); a++)   //if there are for example 8 items in BST, there are 8 items in vector. so you loop through and print each item's information (while it has already been sorted to the user's desire) until the end of the vector. total of 8 loops and thus 8 displays of information.
    {
        name = orderedVec[a]->getName();        
        type = orderedVec[a]->getType();
        level = orderedVec[a]->getLevel();
        value = orderedVec[a]->getGoldValue();
        quantity = orderedVec[a]->getQuantity();


        if (type != "CONSUMABLE")
        {
            std::cout << name <<" (" << type << ")\n" <<
            "Level: " << level << "\nValue: " << value << "\n\n";

        }

        else
        {
            std::cout << name <<" (" << type << ")\n" <<
            "Level: " << level << "\nValue: " << value << "\nQuantity: " << quantity <<"\n\n";

        }

    }





}
