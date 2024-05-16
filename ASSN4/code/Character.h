// Character.h
#pragma once
#include <vector>
#include "Monster.h"

using namespace std;

class Character
{
private:
	int attack;
	int defense;
	int gold;
	int level;
	int max_hp;
	int curr_hp;
	int max_mp;
	int curr_mp;
	int max_exp;
	int curr_exp;

public:
	vector<int> curr_position;
	vector<vector<int>> move_history;

	Character();
	~Character();
	void show_status();
	void battle_status();
	void shop_status(int choiceNum, int origin_hp, int origin_mp);
	int change_status(int value, char option, bool shop);
	void random_act();
	bool level_up(bool print_option);
	bool judge_level_up();
	int attack_basic(int defense);
	int attack_skill(int defense);
	int attack_fire(char type, int defense);
	int attack_grass(char type, int defense);
	int attack_water(char type, int defense);
	void character_reward(int reward);
	int character_defense();
	int character_curr_mp();
	int character_curr_hp();
	int character_gold();
};

