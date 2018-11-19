#pragma once
#include <string>

using namespace std;
class StrategyInterface {
public:
	virtual void rollDice();
	virtual void resolveDice();
	virtual void move();
	virtual void buyCards();
};
class Aggressive : public StrategyInterface {
public:
	void rollDice() override;
	void resolveDice() override;
	void move() override;
	void buyCards() override;
};

class Moderate : public StrategyInterface {
	void rollDice() override;
	void resolveDice() override;
	void move() override;
	void buyCards() override;
};

