#pragma once
#include "BirdList.h"
#include <string>
class GGD
{
private:
	BirdList* bird_list;
	std::string bird_type[7] = { "송골매", "암살자 오리", "오리", "탐정 거위", "장의사 거위", "거위", "도도새" };
	bool dodoWin = false;
	bool GameError = false;
	int RoundNumber = 1;
public:
	// Do not change any function declaration from here //
	GGD(); 
	~GGD(); 
	void GameStart(); 
	void RoundProgress(); 
	bool IsGameOver(); 
	void PrintGameResult(); 
	// Do not change any function declaration to here //

	void AddPlayer(); // You can change the function declaration
};

