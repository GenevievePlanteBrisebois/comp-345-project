#pragma once
#include <iostream>
#include <string>
#include "Player/Player/player.h"
#include "Move/Move/Move.h"
#include "BuyCardEngine/BuyCardEngine/BuyCards.h"

using namespace std;
class StrategyInterface {
public:
	virtual void rollDice() = 0;
	virtual void resolveDice() = 0;
	virtual void move() = 0;
	virtual void buyCards() = 0;
};
//aggressive player
class Aggressive : public StrategyInterface {
public:
	Aggressive();
	~Aggressive();
	void rollDice() override;
	void resolveDice() override;
	void move() override;
	void buyCards() override;
};
//moderate player
class Moderate : public StrategyInterface {
	void rollDice() override;
	void resolveDice() override;
	void move() override;
	void buyCards() override;
};

