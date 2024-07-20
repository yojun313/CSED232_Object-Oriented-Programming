#include "Bird.h"
#include "BirdList.h"

#include <iostream>

// Static member initialization
int Bird::kill_limit = 1;
int Bird::default_kill_limit = 1;

// Default constructor
Bird::Bird() {
}

// Destructor
Bird::~Bird() {

}

// Function to get the player's name
std::string Bird::GetPlayerName() const {
	return this->player_name;
}

// Function to check if the bird is alive
bool Bird::GetisAlive()
{
	return this->isAlive;
}

// Function to check if the bird has attacked someone
bool Bird::GetAttackSomeone()
{
	return this->AttackSomeone;
}

// Function to mark the bird as killed
void Bird::Killed()
{
	this->isAlive = false;
}

// Function to increment the vote count for the bird
void Bird::Add_VoteCount()
{
	this->VoteCount++;
}

// Function to reset the vote count for the bird
void Bird::Reset_VoteCount()
{
	this->VoteCount = 0;
}

// Function to get the current vote count for the bird
int Bird::GetVoteCount()
{
	return this->VoteCount;
}

// Function to get the default kill limit for the bird
int Bird::GetDefaultKillLimit()
{
	return this->default_kill_limit;
}

// Function to reset the 'AttackSomeone' flag for the bird
void Bird::Reset_AttackSomeone()
{
	this->AttackSomeone = false;
}

// Function to get the kill limit for the bird
int Bird::GetKillLimit()
{
	return this->kill_limit;
}