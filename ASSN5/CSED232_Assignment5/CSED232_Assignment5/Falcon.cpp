#include "Falcon.h"

#include <iostream>
#include <string>

using namespace std;


Falcon::Falcon() {

}

// Constructor to initialize Falcon with a player name
Falcon::Falcon(std::string player_name) {
	this->player_name = player_name;
}

Falcon::~Falcon() {

}

// Function to execute Falcon's skill
void Falcon::Skill(BirdList* birdList)
{
	if (AskSkill() == true)
	{
		string playername;
		cout << "살해하고 싶은 플레이어의 이름을 입력하세요: ";
		cin >> playername;
		AttackSomeone = true;

		// Find the bird corresponding to the entered player name and mark it as killed
		birdList->FindBird(playername)->GetBird()->Killed();
		cout << "전체 메시지: " << playername << "이(가) 무참히 살해당하였습니다.." << endl;
	}
	return;
}

// Function to inquire about Falcon's skill availability
bool Falcon::AskSkill()
{
	char UseSkill;
	cout << this->player_name << "님 당신은 송골매입니다." << endl;
	
	cout << "살조를 사용하시겠습니까? [Y/N]: ";
	cin >> UseSkill;

	if (UseSkill == 'Y') return true;
	else return false;
}

// Function to get the job of Falcon
string Falcon::GetJob() {
	return "송골매";
}