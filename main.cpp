#include "Character.hpp"




int main()
{
    //test

    Character Arthur;           
    cout <<"Arthur is: " <<endl;
    cout << Arthur.getName() << endl;       //works
    cout << Arthur.isEnemy() <<endl;
    
    Character Davis ("1john", "HUMAN", -6, 55, 45, false);
    
    Davis.setName("johnFB");
    cout << Davis.getName() <<endl;

    Davis.setName("newn43dje");
    cout << Davis.getName() <<endl;

    cout << Davis.getRace() <<endl;
    cout << Davis.getVitality() <<endl;
    cout << Davis.getArmor() <<endl;
    cout << Davis.getLevel() <<endl;
    cout << Davis.isEnemy() <<endl;
    cout << Davis.isEnemy() <<endl;





    return 0;
}
