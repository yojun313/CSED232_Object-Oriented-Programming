#include "DetectiveGoose.h"

#include <iostream>
#include <string>

using namespace std;

DetectiveGoose::DetectiveGoose() {

}

// Constructor to initialize DetectiveGoose with a player name
DetectiveGoose::DetectiveGoose(string player_name) {
	this->player_name = player_name;
}

DetectiveGoose::~DetectiveGoose() {

}

// Function to execute Detective Goose's skill
void DetectiveGoose::Skill(BirdList* birdList)
{
	// Check if the player wants to use the skill
	if (AskSkill() == true)
	{
		string playername;
		cout << "조사하고 싶은 플레이어의 이름을 입력하세요: ";
		cin >> playername;

		// Check if the investigated player attacked someone
		if (birdList->FindBird(playername)->GetBird()->GetAttackSomeone() == true)
		{
			cout << playername << "은(는) 이번 라운드에 누군가를 무참히 살해하였습니다..!" << endl;
		}
		else
		{
			cout << playername << "은(는) 이번 라운드에 아무도 해치지 않았습니다." << endl;
		}
	}
}

// Function to ask the player if they want to use the skill
bool DetectiveGoose::AskSkill()
{
	char UseSkill;
	cout << this->player_name << "님 당신은 탐정 거위입니다." << endl;
	cout << "조사를 사용하시겠습니까? [Y/N]: ";
	cin >> UseSkill;

	if (UseSkill == 'Y') return true;
	else return false;
}

// Function to get the job of Detective Goose
string DetectiveGoose::GetJob() {
	return "탐정 거위";
}