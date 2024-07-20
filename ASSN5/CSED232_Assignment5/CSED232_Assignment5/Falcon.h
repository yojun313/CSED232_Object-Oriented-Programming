#pragma once
#include "Bird.h"
#include "BirdList.h"
#include <string>

class Falcon : public Bird
{
protected:

private:

public:
    Falcon();
    Falcon(std::string player_name);
    ~Falcon();
    void Skill(BirdList*);
    bool AskSkill();
    std::string GetJob();
};

