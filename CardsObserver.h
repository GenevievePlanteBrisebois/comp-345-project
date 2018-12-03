#pragma once
#include <iostream>
#include "Observer.h"
//implementation of cards effects
class CardsObserver : public Observer {
public:
	void notifyCardUsed(string card);
	void notifyCardEffect(string effect);
	void notifyCardBought(string cardbought);

};