#pragma once
#include "Bird.h"
#include "BirdList.h"
#include <string>

class Falcon : public Bird
{
protected:

private:
    int KillChance_PerRound = 1;

public:
    Falcon();
    Falcon(std::string player_name);
    ~Falcon();
    void Skill(BirdList*);
    void Reset_KillChance_PerRound();
    bool AskSkill();
    std::string GetJob();
};

