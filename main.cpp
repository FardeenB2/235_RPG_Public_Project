#include "Character.hpp"
#include "Mage.hpp"
#include "Scoundrel.hpp"
#include "Barbarian.hpp"

int main()
{
    Mage defaultMage;
    defaultMage.setName("defaultMage");
    defaultMage.setRace("ELF");
    defaultMage.setVitality(5);
    defaultMage.setArmor(3);
    defaultMage.setLevel(2);
    defaultMage.setEnemy();

    cout << defaultMage.getName() << " is a Level " << defaultMage.getLevel() <<" "<< defaultMage.getRace() << "\nVitality: " 
    << defaultMage.getVitality() << "\nArmor: " 
    << defaultMage.getArmor() <<"\nThey are "
    << defaultMage.isEnemy();

    cout << "\n";   //-----------------------

    Mage SPYNACH ("SPYNACH", "ELF", 6, 4, 4, false);
   

    cout << SPYNACH.getName() << " is a Level " << SPYNACH.getLevel() <<" "<< SPYNACH.getRace() << "\nVitality: " 
    << SPYNACH.getVitality() << "\nArmor: " 
    << SPYNACH.getArmor() <<"\nThey are "
    << SPYNACH.isEnemy();


    SPYNACH.setSchool("Illusion");
    SPYNACH.setCastingWeapon("Wand");
    SPYNACH.setIncarnateSummon (true);

    cout << "\n" << SPYNACH.getSchool();
    cout << "\n"  << SPYNACH.getCastingWeapon();
    cout << "\n"  << SPYNACH.hasIncarnateSummon();

    cout << "\n";
    //------------------------------


    Scoundrel defaultScoundel;
    defaultScoundel.setName("FLEA");
    defaultScoundel.setRace("HUMAN");
    defaultScoundel.setVitality(6);
    defaultScoundel.setArmor(4);
    defaultScoundel.setLevel(3);
    defaultScoundel.setEnemy();

    cout << defaultScoundel.getName() << " is a Level " << defaultScoundel.getLevel() <<" "<< defaultScoundel.getRace() << "\nVitality: " 
    << defaultScoundel.getVitality() << "\nArmor: " 
    << defaultScoundel.getArmor() <<"\nThey are "
    << defaultScoundel.isEnemy();

    cout << "\n"; //---------------------------

    Scoundrel FLEA ("FLEA", "DWARF", 12, 7, 5, false, "rune", "shadowblade", false);

    cout << FLEA.getDagger() <<endl;

    FLEA.setDagger("Adamant");
    FLEA.setFaction("Cutpurse");
    FLEA.setDisguise (true);

    cout << "\n" << FLEA.getDagger();
    cout << "\n" << FLEA.getFaction();
    cout << "\n" << FLEA.hasDisguise();

    cout << "\n"; //---------------------------

//new test

}
