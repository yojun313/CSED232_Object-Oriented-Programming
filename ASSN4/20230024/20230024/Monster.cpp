// Monster.cpp
#include "Monster.h"
#include "Character.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;



// Constructor for the Monster class
Monster::Monster(vector<int> curr_position, bool boss)
{
    difficulty = curr_position[0] + curr_position[1]; // Calculate difficulty based on position coordinates
    max_hp = 50 + (difficulty * 5); // Set maximum HP based on difficulty
    curr_hp = max_hp; // Current HP is set to maximum at creation
    attack = 5 + (difficulty * 2); // Set attack strength based on difficulty
    defense = round(2 + (difficulty / 2)); // Set defense, rounded to ensure it is an integer
    reward = 100 + difficulty * 10; // Set reward for defeating the monster
    type = _random_type(); // Assign a random type to the monster

    if (boss == true) // If the monster is a boss
    {
        max_hp = 200; // Bosses have fixed high HP
        curr_hp = max_hp;
        attack = 30; // Bosses have high attack value
        defense = 10; // Bosses have high defense
    }
}

// Destructor for the Monster class
Monster::~Monster() {}

// Display current status of the monster in battle
void Monster::battle_status()
{
    cout << "================================" << endl;
    cout << "Monster status" << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "HP: " << curr_hp << " / " << max_hp << endl;
}

// Function to update the monster's HP after taking damage
void Monster::change_status(int damage)
{
    curr_hp -= damage; // Subtract damage from current HP
}

// Function to randomly assign a type to a monster
char Monster::_random_type()
{
    int elements[4] = { 'G', 'W', 'F', 'B' }; // Array of possible types: Grass, Water, Fire, Basic 

    // Initialize random seed
    srand(time(NULL));

    type = elements[rand() % 4]; // Randomly select a type from the elements array

    return type; // Return the selected type
}

// Function to calculate damage dealt to a character
int Monster::attack_character(int defense)
{
    int damage = attack - defense; // Calculate damage as monster's attack minus character's defense
    if (damage < 0) damage = 0; // Ensure that damage is not negative
    return damage; // Return the calculated damage
}

// Accessor function to get the monster's type
char Monster::monster_type()
{
    return type; // Return the monster's type
}

// Accessor function to get the monster's defense
int Monster::monster_defense()
{
    return defense; // Return the monster's defense
}

// Accessor function to get the monster's current HP
int Monster::monster_curr_hp()
{
    return curr_hp; // Return the current HP of the monster
}

// Accessor function to get the reward for defeating the monster
int Monster::monster_reward()
{
    return reward; // Return the reward for defeating the monster
}
