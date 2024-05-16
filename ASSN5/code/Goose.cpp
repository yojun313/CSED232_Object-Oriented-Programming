#include "Goose.h"

#include <iostream>

using namespace std;

Goose::Goose() {

}

// Constructor to initialize Goose with a player name
Goose::Goose(std::string player_name){
	this->player_name = player_name;
}

Goose::~Goose() {

}

// Function to execute Goose's skill
void Goose::Skill(BirdList*) {
	cout << this->player_name << "님 당신은 거위입니다." << endl;
	cout << "당신은 능력이 없는 조류입니다." << std::endl;
}

// Function to get the job of Goose
string Goose::GetJob() {
	return "거위";
}

// Function to inquire about Goose's skill availability
bool Goose::AskSkill() {
	return true;
}