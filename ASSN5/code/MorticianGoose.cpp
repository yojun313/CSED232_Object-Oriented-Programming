#include "MorticianGoose.h"

#include <iostream>
#include <string>

using namespace std;

MorticianGoose::MorticianGoose() {

}

// Constructor to initialize MorticianGoose with a player name
MorticianGoose::MorticianGoose(string player_name) {
	this->player_name = player_name;
}

MorticianGoose::~MorticianGoose() {

}

// Function to execute MorticianGoose's skill
void MorticianGoose::Skill(BirdList* birdList)
{
	if (AskSkill() == true)
	{
		BirdNode* current = birdList->GetHead();
		bool DeadCheck = false;
		string playername;
		while (current != nullptr)
		{
			Bird* bird = current->GetBird();
			if (bird->GetisAlive() == false)
			{
				DeadCheck = true;
				break;
			}
			current = current->GetNext();
		}
		if (DeadCheck == false)
		{
			cout << "염습 가능 대상이 없습니다." << endl;
			return;
		}
		else
		{
			cout << "염습하고 싶은 플레이어의 이름을 입력하세요: ";
			cin >> playername;
			string job = birdList->FindBird(playername)->GetBird()->GetJob();
			cout << playername << "의 역할은 " << job << "입니다." << endl;
		}
	}
	return;
}

// Function to inquire about MorticianGoose's skill availability
bool MorticianGoose::AskSkill()
{
	char UseSkill;
	cout << this->player_name << "님 당신은 장의사 거위입니다." << endl;
	cout << "염습을 사용하시겠습니까? [Y/N]: ";
	cin >> UseSkill;
	
	if (UseSkill == 'Y') return true;
	else return false;
}

// Function to get the job of MorticianGoose
string MorticianGoose::GetJob() {
	return "장의사 거위";
}