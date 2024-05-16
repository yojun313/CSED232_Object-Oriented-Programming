#pragma once
#include "Bird.h"
#include "BirdList.h"
#include <string>

class Duck : public Bird
{
protected:

private:

public:
    Duck();
    Duck(std::string player_name);
    ~Duck();
    void Skill(BirdList*);
    bool AskSkill();
    std::string GetJob();
};