#include <iostream>
#include "gardener.h"

using namespace std;

int main()
{
    Garden* garden = new Garden(6);
    Gardener* gardener = new Gardener(garden);

    gardener->_garden->plant(1, Potato::instance(), 3);
    gardener->_garden->plant(2, Pea::instance(), 3);
    gardener->_garden->plant(4, Pea::instance(), 3);
    gardener->_garden->plant(5, Rose::instance(), 4);
    gardener->_garden->plant(6, Onion::instance(), 4);
    // Time->Month
    // August:Onion 8(harvesting)-4(planinting)= 4(RipeningTime) ,Potato: 8-5=3 
    //June: Pea: 3-6=3
    cout << "IDs of parcels that can be harvested in August: ";
    for( int i : gardener->_garden->canHarvest(8)){
        cout << i << " ";
    }
    cout << endl;

	Potato::destroy();
	Pea::destroy();
	Onion::destroy();
	Tulip::destroy();
	Carnation::destroy();
	Rose::destroy();
    delete garden;
    delete gardener;

    return 0;
}
