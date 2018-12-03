#include "CardsObserver.h"
#include <iostream>

void CardsObserver::notifyCardUsed(string card) {
	cout << "You bought: " << card << endl;
}

void  CardsObserver::notifyCardEffect(string effect) {
	cout << effect << endl;
}

void CardsObserver::notifyCardBought(string cardbought) {
	cout << "You bought: " << cardbought;
}
