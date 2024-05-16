#include "AssassinDuck.h"

#include <iostream>
#include <string>
#include "Macro.h"

using namespace std;

// Default constructor
AssassinDuck::AssassinDuck() {

}

// Parameterized constructor to initialize the player name
AssassinDuck::AssassinDuck(string player_name) {
	this->player_name = player_name;
}

// Destructor
AssassinDuck::~AssassinDuck() {

}

// Function to execute the skill of the Assassin Duck
void AssassinDuck::Skill(BirdList* birdList)
{
	string playername;
	// Check if the skill can be used
	if (AskSkill() == true)
	{
		int playerjob = 0;
		cout << "암살하고 싶은 플레이어의 이름을 입력하세요: ";
		cin >> playername;
		cout << "암살하고 싶은 플레이어의 역할 번호를 입력하세요: ";
		cin >> playerjob;

		// Check if the target player's role matches the specified role
		if (birdList->FindBird(playername)->GetBird()->GetJob() == BirdRoleName[playerjob])
		{
			// If matched, eliminate the target player
			birdList->FindBird(playername)->GetBird()->Killed();
			this->AssassinChance++;
			AttackSomeone = true;
			cout << "전체 메시지: " << playername << "이(가) 무참히 살해당하였습니다.." << endl;
		}
		else
		{
			// If not matched, eliminate the Assassin Duck
			this->isAlive = false;
			cout << "전체 메시지: " << this->player_name << "은(는) 극단적 선택을 하였습니다." << endl;
			return;
		}
	}
	// Check if the Assassin Duck can use the kill skill
	char UseSkill;
	if (kill_limit >= 1)
	{
		cout << "살조를 사용하시겠습니까? [Y/N]: ";
		cin >> UseSkill;

		if (UseSkill == 'Y')
		{
			cout << "살해하고 싶은 플레이어의 이름을 입력하세요: ";
			cin >> playername;

			// Assassinate the target player
			birdList->FindBird(playername)->GetBird()->Killed();
			kill_limit -= 1;
			AttackSomeone = true;
			cout << "전체 메시지: " << playername << "이(가) 무참히 살해당하였습니다.." << endl;
		}
		else return;
	}
	cout << "라운드당 오리 진영의 살조 제한 횟수에 도달하였습니다." << endl;
	return;
}

// Function to prompt the Assassin Duck to use its skill
bool AssassinDuck::AskSkill()
{
	cout << this->player_name << "님 당신은 암살자 오리입니다." << endl;
	if (this->AssassinChance < 2)
	{
		char UseSkill;
		cout << "암살을 사용하시겠습니까? [Y/N]: ";
		cin >> UseSkill;

		if (UseSkill == 'Y') return true;
		else return false;
	}
	else
	{
		cout << "게임당 오리 진영의 암살 제한 횟수에 도달하였습니다." << endl;
		return false;
	}
}

// Function to get the job of the Assassin Duck
string AssassinDuck::GetJob() {
	return "암살자 오리";
}