#include "Duck.h"

#include <iostream>
#include <string>

using namespace std;

Duck::Duck() {

}

// Constructor to initialize Duck with a player name
Duck::Duck(string player_name) {
	this->player_name = player_name;
}

Duck::~Duck() {

}

// Function to execute Duck's skill
void Duck::Skill(BirdList* birdList)
{
	if (AskSkill() == true)
	{
		string playername;
		cout << "살해하고 싶은 플레이어의 이름을 입력하세요: ";
		cin >> playername;

		// Find the bird corresponding to the entered player name and mark it as killed
		birdList->FindBird(playername)->GetBird()->Killed();
		AttackSomeone = true;
		kill_limit -= 1;
		cout << "전체 메시지: " << playername << "이(가) 무참히 살해당하였습니다.." << endl;
	}
	return;
}

// Function to inquire about Duck's skill availability
bool Duck::AskSkill()
{
	char UseSkill;
	cout << this->player_name << "님 당신은 오리입니다." << endl;
	if (kill_limit >= 1)
	{
		cout << "살조를 사용하시겠습니까? [Y/N]: ";
		cin >> UseSkill;

		if (UseSkill == 'Y') return true;
		else return false;
	}
	cout << "라운드당 오리 진영의 살조 제한 횟수에 도달하였습니다." << endl;
	return false;
}

// Function to get the job of Duck
string Duck::GetJob() {
	return "오리";
}