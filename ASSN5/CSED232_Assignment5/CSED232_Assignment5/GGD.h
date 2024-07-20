#pragma once
#include "BirdList.h"
#include <string>
class GGD
{
private:
	BirdList* bird_list;
	std::string bird_type[7] = { "�۰��", "�ϻ��� ����", "����", "Ž�� ����", "���ǻ� ����", "����", "������" };
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

