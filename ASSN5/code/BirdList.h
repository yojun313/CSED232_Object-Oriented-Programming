#pragma once
#include "BirdNode.h"

#include <string> 

class BirdList
{
private:
	BirdNode* head = nullptr;
	BirdNode* tail = nullptr;
	int BirdCount = 0;
public:
	BirdList();
	~BirdList();

	BirdNode* GetHead() const;
	BirdNode* GetTail() const;
	void AddBirdNode(BirdNode*);
	void RoundReset();
	int GetBirdCount();
	BirdNode* FindBird(std::string playername);
	Bird* ConductVoting(int NeutralVote);
	char JudgeWin();

};

