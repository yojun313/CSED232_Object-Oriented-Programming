#pragma once
#include "Bird.h"
#include "BirdList.h"
#include <string>

class AssassinDuck : public Bird
{
protected:

private:
    int AssassinChance = 0;

public:
    AssassinDuck();
    AssassinDuck(std::string player_name);
    ~AssassinDuck();
    void Skill(BirdList*);
    bool AskSkill();
    std::string GetJob();
};