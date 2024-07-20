#pragma once
#include "Bird.h"
#include <string>

class DodoBird : public Bird
{
protected:

private:

public:
    DodoBird();
    DodoBird(std::string player_name);
    ~DodoBird();
    void Skill(BirdList*);
    bool AskSkill();
    std::string GetJob();
};

