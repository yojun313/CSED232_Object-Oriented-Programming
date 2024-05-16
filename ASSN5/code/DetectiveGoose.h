#pragma once
#include "Bird.h"
#include "BirdList.h"
#include <string>

class DetectiveGoose : public Bird
{
protected:

private:

public:
	DetectiveGoose();
	DetectiveGoose(std::string player_name);
	~DetectiveGoose();
	void Skill(BirdList*);
	bool AskSkill();
	std::string GetJob();
};

