#include "BirdList.h"

#include "Bird.h"
#include "Goose.h"
#include "Falcon.h"

BirdList::BirdList() {
}

BirdList::~BirdList() {
}

// Function to get the head of the bird list
BirdNode* BirdList::GetHead() const {
    return this->head;
}

// Function to get the tail of the bird list
BirdNode* BirdList::GetTail() const {
    return this->tail;
}

// Function to add a new bird node to the list
void BirdList::AddBirdNode(BirdNode* node) {
    if (this->head == nullptr)
    {
        // If the list is empty, set the new node as both head and tail
        this->head = node;
        this->tail = node;
    }
    else {
        // If the list is not empty, set the new node as the "tail's next"
        this->tail->SetNext(node);
        // Update the tail to be the new node
        this->tail = node;
    }
    this->BirdCount++;
}

// Function to find a bird by its player name
BirdNode* BirdList::FindBird(std::string playername)
{
    BirdNode* current = this->head;
    while (current != nullptr)
    {
        Bird* bird = current->GetBird();
        if (bird->GetPlayerName() == playername)
        {
            return current;
        }
        current = current->GetNext();
    }
    return NULL;
}

// Function to get the total count of birds in the list
int BirdList::GetBirdCount()
{
    return this->BirdCount;
}

// Function to conduct voting and determine the most voted bird
Bird* BirdList::ConductVoting(int NeutralVote)
{
    Bird* mostVotedBird = nullptr;
    BirdNode* current = this->head;
    int maxVotes = 0;

    // First traversal: Determine the maximum vote count
    while (current != nullptr) {
        Bird* bird = current->GetBird();
        if (bird->GetVoteCount() > maxVotes) {
            maxVotes = bird->GetVoteCount();
        }
        current = current->GetNext();
    }

    current = this->head;
    int maxVotedBirdsCount = 0;

    // Second traversal: Find the most voted bird(s) and handle ties
    while (current != nullptr) {
        Bird* bird = current->GetBird();
        if (bird->GetVoteCount() == maxVotes) {
            maxVotedBirdsCount++;
            mostVotedBird = bird;
        }
        current = current->GetNext();
    }

    // Handle the case where neutral votes are equal to the maximum votes
    if (NeutralVote == maxVotes) {
        maxVotedBirdsCount++;
    }

    // If there are multiple birds with the same maximum votes, return nullptr
    if (maxVotedBirdsCount > 1) {
        return nullptr;  
    }
    return mostVotedBird;
}

// Function to reset each bird's vote count and attack status for a new round
void BirdList::RoundReset()
{
    BirdNode* current = this->head;
    while (current != nullptr)
    {
        Bird* bird = current->GetBird();
        bird->Reset_VoteCount();
        bird->Reset_AttackSomeone();

        current = current->GetNext();
    }
    // Reset kill limit for ducks per round
    Bird::Set_Kill_limit(this->head->GetBird()->GetDefaultKillLimit()); // reset Duck Kill limit per round
}

// Function to judge the win condition of the game
char BirdList::JudgeWin()
{
    int gooseCount = 0;
    int duckCount = 0;
    int falconCount = 0;
    int dodoCount = 0;

    BirdNode* current = this->head;
    while (current != nullptr) {
        Bird* bird = current->GetBird();
        if (bird->GetisAlive() == true) {
            std::string job = bird->GetJob();
            if (job == "거위" || job == "탐정 거위" || job == "장의사 거위")
            {
                gooseCount++;
            }
            else if (job == "오리" || job == "암살자 오리")
            {
                duckCount++;
            }
            else if (job == "송골매")
            {
                falconCount++;
            }
            else if (job == "도도새") {
                dodoCount++;
            }
        }
        current = current->GetNext();
    }
    int allCount = gooseCount + duckCount + falconCount + dodoCount;

    // Goose win condition
    if (gooseCount > 0 && duckCount == 0 && falconCount == 0) {
        return 'G';
    }

    // Duck win condition
    if (duckCount > 0 && duckCount >= allCount - duckCount) {

        if (allCount == 2)
        {
            if (duckCount == 1 && falconCount == 1) return 'F';
            else return 'D';
        }
    }

    // Falcon win condition
    if (falconCount == 1 && allCount - 1 <= 1) {
        return 'F';
    }
    return 'N'; // No winner yet
}