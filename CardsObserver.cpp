#include "CardsObserver.h"
#include <iostream>

void CardsObserver::CardUsed(string card) {
	cout << "You bought: " << card << endl;
}

void  CardsObserver::CardEffect(string effect) {
	cout << effect << endl;
}

void CardsObserver::CardBought(string cardbought) {

}
