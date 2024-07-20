// Battle.cpp
#include "Battle.h"
#include "Character.h"
#include "Monster.h"
#include <iostream>

using namespace std;

// Constructor for the Battle class
Battle::Battle(Character* myCharacter, Monster* myMonster)
{
    character_defense = myCharacter->character_defense(); // Set character defense from character object
    monster_defense = myMonster->monster_defense(); // Set monster defense from monster object
    monster_type = myMonster->monster_type(); // Set monster type from monster object
}

// Destructor for the Battle class
Battle::~Battle() {}

// Private method to present action choices and get user input
int Battle::_choose_action(Character* myCharacter, Monster* myMonster)
{
    myCharacter->battle_status(); // Display character's battle status
    myMonster->battle_status(); // Display monster's battle status

    // Display action choices to the player
    cout << "================================" << endl;
    cout << "Choose your action" << endl;
    cout << "1. Meele attack" << endl;
    cout << "2. Magic attack" << endl;
    cout << "3. Fire magic attack" << endl;
    cout << "4. Grass magic attack" << endl;
    cout << "5. Water magic attack" << endl;

    int actionNum = 0;

    // Input loop to ensure valid action number is chosen
    while (true)
    {
        cout << "> ";
        cin >> actionNum;
        if (actionNum >= 1 && actionNum <= 5) return actionNum; // Return valid action number
    }
}

// Public method to conduct the battle sequence
char Battle::battle_action(Character* myCharacter, Monster* myMonster)
{
    cout << "Wild monster appeared!\n" << endl;
    while (true)
    {
        int actionNum = _choose_action(myCharacter, myMonster); // Get the chosen action from user
        int CtoM_damage = 0; // Initialize damage character will deal to monster

        // Check if action is a magic attack and if character has enough MP
        if (actionNum != 1 && myCharacter->character_curr_mp() < 15)
            cout << "\nNot enough MP..." << endl;
        else
        {
            // Process the selected action and calculate damage
            switch (actionNum)
            {
            case 1:
                CtoM_damage = myCharacter->attack_basic(monster_defense); // Basic melee attack
                break;
            case 2:
                CtoM_damage = myCharacter->attack_skill(monster_defense); // General magic attack
                break;
            case 3:
                CtoM_damage = myCharacter->attack_fire(monster_type, monster_defense); // Fire magic attack
                break;
            case 4:
                CtoM_damage = myCharacter->attack_grass(monster_type, monster_defense); // Grass magic attack
                break;
            case 5:
                CtoM_damage = myCharacter->attack_water(monster_type, monster_defense); // Water magic attack
                break;
            }
            myMonster->change_status(CtoM_damage); // Apply damage to monster
            cout << "\nYou hit the monster with " << CtoM_damage << " damage!" << endl;
        }

        // Monster attacks back and damage is applied to the character
        int MtoC_damage = myMonster->attack_character(character_defense);
        myCharacter->change_status(MtoC_damage, 'h', false); // 'h' indicates health damage, 'false' for no defense boost
        cout << "Monster hit you with " << MtoC_damage << " damage!\n" << endl;

        // Check for defeat conditions
        if (myCharacter->character_curr_hp() < 0)
        {
            cout << "\nYou Died..." << endl;
            return 'M'; // Return 'M' if monster wins
        }
        if (myMonster->monster_curr_hp() < 0)
        {
            // Monster defeated, display reward and update character
            cout << "You defeated the monster!" << endl;
            cout << "Reward: " << myMonster->monster_reward() << " Gold, " << myMonster->monster_reward() << " EXP\n" << endl;
            myCharacter->character_reward(myMonster->monster_reward());
            return 'C'; // Return 'C' if character wins
        }
    }
}
