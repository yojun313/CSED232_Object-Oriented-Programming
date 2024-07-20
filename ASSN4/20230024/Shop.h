// Shop.h
#pragma once
#include "Character.h"

class Shop
{
private:
	int plus_attack;
	int plus_defense;
	int plus_exp;

public:
	Shop();
	~Shop();
	void shop_choice(Character* myCharacter);
	void shop_product(int choiceNum);
};

