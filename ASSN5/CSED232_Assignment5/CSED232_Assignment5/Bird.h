#pragma once
#include <string>

class BirdList;

class Bird
{
protected:
	bool AttackSomeone = false;
	bool isAlive = true;
	int VoteCount = 0;

	static int kill_limit;
	static int default_kill_limit;

	std::string player_name;
public:
	Bird();
	virtual ~Bird();

	static void Set_Kill_limit(int value) {
		kill_limit = value;
		default_kill_limit = value;
	}
	

	std::string GetPlayerName() const;
	bool GetisAlive();
	bool GetAttackSomeone();
	void Killed();
	int GetVoteCount();
	int GetKillLimit();
	void Add_VoteCount();
	void Reset_VoteCount();
	void Reset_AttackSomeone();
	int GetDefaultKillLimit();

	virtual void Skill(BirdList*)=0;
	virtual bool AskSkill() = 0;
	virtual std::string GetJob() = 0;
};

