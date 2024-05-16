// Map.h
#pragma once
#include <vector>
#include "Character.h"

using namespace std;

class Map
{
private:
	std::vector<std::vector<char>> map_info;

public:
	Map();
	~Map();
	void draw_map(Character* myCaracter);
	int map_option_select();
	char map_move(Character* myCharacter);
};

