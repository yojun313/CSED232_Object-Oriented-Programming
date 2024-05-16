// Monster.h
#pragma once
#include <vector>
#include "Character.h"

using namespace std;

class Monster
{
private:
	int difficulty;
	int curr_hp;
	int max_hp;
	int attack;
	int reward;
	int defense;
	char type;
	char _random_type();

public:
	Monster(vector<int> curr_position, bool boss);
	~Monster();
	char monster_type();
	int monster_defense();
	int monster_curr_hp();
	int monster_reward();
	void battle_status();
	void change_status(int damage);
	int attack_character(int defense);
};

