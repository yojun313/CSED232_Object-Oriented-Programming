#pragma once
#include "Bird.h"
#include "BirdList.h"
#include <string>

class MorticianGoose : public Bird
{
protected:

private:

public:
    MorticianGoose();
    MorticianGoose(std::string player_name);
    ~MorticianGoose();
    void Skill(BirdList*);
    bool AskSkill();
    std::string GetJob();
};

