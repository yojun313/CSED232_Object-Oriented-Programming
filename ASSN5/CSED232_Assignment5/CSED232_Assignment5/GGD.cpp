#include <iostream>
#include <string>
#include "GGD.h"
#include "Macro.h"
#include "Falcon.h"
#include "AssassinDuck.h"
#include "Duck.h"
#include "DetectiveGoose.h"
#include "MorticianGoose.h"
#include "Goose.h"
#include "DodoBird.h"


using namespace std;

// Constructor: Initializes the GGD object with an empty bird list.
GGD::GGD() {
	bird_list = new BirdList();
}

// Destructor: Frees the memory allocated for the bird list.
GGD::~GGD() {

}

// Function to start the game by setting up players and game parameters.
void GGD::GameStart() {
	int select;
	bool game_start = false;
	int value = 0;
	while (!game_start) {
		// Display the game setup menu
		std::cout << "------------게임 설정 메뉴-------------\n";
		std::cout << "1. 플레이어 추가\n";
		std::cout << "2. 라운드당 오리 진영 살조 제한 횟수 설정\n";
		std::cout << "3. 게임 시작하기!\n";
		std::cout << "---------------------------------------\n";
		std::cout << "메뉴 번호를 입력하세요: ";
		std::cin >> select;

		// Process user input based on the selected menu option
		switch (select)
		{
		case 1:
			AddPlayer(); // Add a new player to the game
			break;
		case 2:
			cout << "값을 입력하세요: ";
			cin >> value;
			Bird::Set_Kill_limit(value); // Set the kill limit for ducks per round
			break;
		case 3:
			if ((this->RoundNumber == 1 && IsGameOver() == true) || bird_list->GetHead() == nullptr) std::cout << "게임을 시작할 수 없습니다!!" << endl;
			else
			{
				std::cout << "게임 시작!!" << endl; // Start the game
				game_start = true;
			}
			break;
		default:
			break;
		}
	}
}
// Function to progress through each round of the game.
void GGD::RoundProgress() {
	int NeutralVote = 0;
	char VoteCheck;
	string VoteName;
	BirdNode* current;
	BirdNode* voteCurrent;

	while (true)
	{
		cout << "----------------Round " << this->RoundNumber << "----------------" << endl;
		// Skill execution phase for each bird
		for (int i = 0; i <= 6; i++)
		{
			current = bird_list->GetHead();
			while (current != nullptr) {
				Bird* bird = current->GetBird();
				if (bird->GetJob() == bird_type[i] && bird->GetisAlive() == true) {
					bird->Skill(bird_list);
				}
				current = current->GetNext();
			}
		}

		// Voting phase
		current = bird_list->GetHead();
		while (current != nullptr)
		{
			Bird* bird = current->GetBird();
			if (bird->GetJob() == "송골매" && bird->GetisAlive() == true)
			{
				cout << bird->GetPlayerName() << "님은 송골매이므로 무효표에 자동 투표됩니다." << endl;
				NeutralVote++;

			}
			else if (bird->GetisAlive() == true)
			{
				cout << bird->GetPlayerName() << "님 투표를 하시겠습니까? [Y/N]: ";
				cin >> VoteCheck;
				if (VoteCheck == 'Y')
				{
					cout << "투표하고 싶은 플레이어의 이름을 입력하세요: ";
					cin >> VoteName;
					voteCurrent = bird_list->GetHead();
					while (voteCurrent != nullptr)
					{
						Bird* votebird = voteCurrent->GetBird();
						if (votebird->GetPlayerName() == VoteName && votebird->GetisAlive() == true) votebird->Add_VoteCount();
						voteCurrent = voteCurrent->GetNext();
					}
				}
				else NeutralVote++;
			}
			current = current->GetNext();
		}
		// Determine the result of the vote
		Bird* VotedBird = bird_list->ConductVoting(NeutralVote);
		if (VotedBird == nullptr)
		{
			cout << "전체 메시지: 이번 투표에서는 아무 조류도 당첨되지 않았습니다." << endl;
			this->RoundNumber++;
		}
		else
		{
			VotedBird->Killed();
			cout << "전체 메시지: " << VotedBird->GetPlayerName() << "은(는) 더 좋은 곳으로 갔습니다." << endl;
			if (VotedBird->GetJob() == "오리" || VotedBird->GetJob() == "암살자 오리" || VotedBird->GetJob() == "오리") cout << "전체 메시지: 만세 " << VotedBird->GetPlayerName() << "은(는) 오리입니다!!" << endl;
			else cout << "전체 메시지: 맙소사 " << VotedBird->GetPlayerName() << "은(는) 오리가 아닙니다!!" << endl;

			if (VotedBird->GetJob() == "도도새")
			{
				this->dodoWin = true;
				return;
			}
		}
		// Check if the game is over
		if (IsGameOver() == true) return;
		else bird_list->RoundReset();
	}
}

// Function to check if the game is over.
bool GGD::IsGameOver() {
	bool res = false;

    if (bird_list->JudgeWin() == 'N') res = false;
	else if (this->dodoWin == true) res = true;
	else res = true;

	return res;
}

// Function to print the result of the game.
void GGD::PrintGameResult() {
	char JudgeResult = bird_list->JudgeWin();
	if (this->dodoWin == true) cout << "전체 메시지: 도도새의 승리입니다!" << endl;
	else if (JudgeResult == 'G') cout << "전체 메시지: 거위의 승리입니다!" << endl;
	else if (JudgeResult == 'D') cout << "전체 메시지: 오리의 승리입니다!" << endl;
	else if (JudgeResult == 'F') cout << "전체 메시지: 송골매의 승리입니다!" << endl;
}

// Function to add a player to the game.
void GGD::AddPlayer() {
	std::string player_name;
	std::cout << "플레이어의 이름을 입력해주세요: ";
	std::cin >> player_name;

	int role_code;
	std::cout << "역할 번호를 입력해주세요: ";
	std::cin >> role_code;

	// Assign a role to the player based on the role code
	switch (BirdRoleCode(role_code)) {
	case BirdRoleCode::kFalcon:
		this->bird_list->AddBirdNode(new BirdNode(new Falcon(player_name)));
		break;
	case BirdRoleCode::kAssassinDuck:
		this->bird_list->AddBirdNode(new BirdNode(new AssassinDuck(player_name)));
		break;
	case BirdRoleCode::kDuck:
		this->bird_list->AddBirdNode(new BirdNode(new Duck(player_name)));
		break;
	case BirdRoleCode::kDetectiveGoose:
		this->bird_list->AddBirdNode(new BirdNode(new DetectiveGoose(player_name)));
		break;
	case BirdRoleCode::kMorticianGoose:
		this->bird_list->AddBirdNode(new BirdNode(new MorticianGoose(player_name)));
		break;
	case BirdRoleCode::kGoose:
		this->bird_list->AddBirdNode(new BirdNode(new Goose(player_name)));
		break;
	case BirdRoleCode::kDodoBird:
		this->bird_list->AddBirdNode(new BirdNode(new DodoBird(player_name)));
		break;
	default:
		break;
	}
}