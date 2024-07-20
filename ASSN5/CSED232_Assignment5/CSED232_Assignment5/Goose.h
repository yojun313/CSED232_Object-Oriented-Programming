#pragma once
#include "Bird.h"
#include <string>

class Goose : public Bird
{
protected:

private:

public:
    Goose();
    Goose(std::string player_name);
    ~Goose();
    void Skill(BirdList*);
    bool AskSkill();
    std::string GetJob();
};

