// Battle.h
#pragma once
#include "Monster.h"
#include "Character.h"

class Battle
{
private:
	int _choose_action(Character* myCharacter, Monster* myMonster);
	int character_defense;
	int monster_type;
	int monster_defense;
public:
	Battle(Character* myCharacter, Monster* myMonster);
	~Battle();
	char battle_action(Character* myCaracter, Monster* myMonster);
};

