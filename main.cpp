#include "Character.hpp"
#include "Mage.hpp"
#include "Scoundrel.hpp"
#include "Barbarian.hpp"

#include "Item.hpp"
#include "BinaryNode.hpp"
#include "BinarySearchTree.hpp" 
#include "Inventory.hpp"
#include <iostream>
using namespace std;
// The test cases within this current Test File are human-modified after Test-generation from the utilization of advanced AI algorithms due to the need for efficient testing. All other files created by the student are human-made.

int main() {
    // Creating Characters
    Character c1;
    Character c2("ROLFE", "HUMAN", 100, 50, 5, false);
    
    // Creating Mages
    Mage m1;
    Mage m2("ELENA", "ELF", 80, 30, 4, false, "ELEMENTAL", "WAND", true);

    // Creating Scoundrels
    Scoundrel s1;
    Scoundrel s2("SMITH", "DWARF", 90, 40, 3, true, "STEEL", "CUTPURSE", true);

    // Creating Barbarians
    Barbarian b1;
    Barbarian b2("Ssstephen", "LIZARD", 120, 60, 6, true, "AXE", "SHIELD", true);



    // Testing Character class
    cout << "Testing the Character class:" << endl;
    cout << "Character 1's Name: " << c1.getName() << endl;
    cout << "Character 2's Name: " << c2.getName() << "| Race: " << c2.getRace() << endl;

    // Testing Mage class
    cout << "\nTesting the Mage class:" << endl;
    cout << "Mage 1's School of Magic: " << m1.getSchool() << endl;
    cout << "Mage 2's Weapon: " << m2.getCastingWeapon() << "| Can Summon Incarnate: " << (m2.hasIncarnateSummon() ? "Yes" : "No") << endl;

    // Testing Scoundrel class
    cout << "\nTesting the Scoundrel class:" << endl;
    cout << "Scoundrel's 1 Faction: " << s1.getFaction() << endl;
    cout << "Scoundrel's 2 Dagger: " << s2.getDagger() << "| Has Disguise: " << (s2.hasDisguise() ? "Yes" : "No") << endl;

    // Testing Barbarian class
    cout << "\nTesting the Barbarian class:" << endl;
    cout << "Barbarian's 1 Main Weapon: " << b1.getMainWeapon() << endl;
    cout << "Barbarian 2 is currently Enraged: " << (b2.getEnrage() ? "Yes" : "No") << endl;
    b2.toggleEnrage();
    cout << "Barbarian 2 is currenty Enraged (after toggling): " << (b2.getEnrage() ? "Yes" : "No") << endl;



    // Creating Inventory and items
    Inventory inventory;
    Item potion("Health Potion", CONSUMABLE, 1, 10, 5);
    Item sword("Sword", WEAPON, 2, 100, 1);
    Item shield("Shield", ARMOR, 3, 75, 1);
    Item bread("Bread", CONSUMABLE, 1, 5, 10);

    // Adding items to the inventory
    inventory.addItem(&potion);
    inventory.addItem(&sword);
    inventory.addItem(&shield);
    inventory.addItem(&bread);

    // Testing Inventory class
    cout << "\nTesting the Inventory class: \n \n";
    cout << "Adding the items to inventory." << endl;
    cout << "Total the Gold Value in Inventory: " << inventory.getTotalGoldValue() << endl;

    // Printing the inventory in order
    cout << "Inventory in order:" << endl;
    inventory.printInventoryInOrder();

    // Removing an item
    cout << "\nRemoving 1 Health Potion from the inventory." << endl;
    inventory.removeItem("Health potion");
    cout << "Inventory after the removal:" << endl;
    inventory.printInventoryInOrder();

    // Finding an item
    cout << "\nFinding 'Sword' in the inventory:" << endl;
    Item* foundItem = inventory.findItem("Sword");
    if (foundItem != nullptr) {
        cout << "Item is found: " << foundItem->getName() << endl;
    } else {
        cout << "Item is not found." << endl;
    }

    // Printing the inventory based on different attributes
    cout << "\nPrinting inventory sorted by descending level):" << endl;
    inventory.printInventory(false, "LEVEL");
    
}
