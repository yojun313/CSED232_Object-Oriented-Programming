#include "DodoBird.h"

#include <iostream>

using namespace std;

DodoBird::DodoBird() {

}

// Constructor to initialize DodoBird with a player name
DodoBird::DodoBird(std::string player_name) {
	this->player_name = player_name;
}

DodoBird::~DodoBird() {

}

// Function to execute DodoBird's skill
void DodoBird::Skill(BirdList*) {
	// Display DodoBird's information and lack of skill
	cout << this->player_name << "님 당신은 도도새입니다." << endl;
	cout << "당신은 능력이 없는 조류입니다." << std::endl;
}

// Function to get the job of DodoBird
string DodoBird::GetJob() {
	return "도도새";
}

// Function to always return true for the skill availability of DodoBird
bool DodoBird::AskSkill() {
	return true;
}