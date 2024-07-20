// Character.cpp
#include <iostream>
#include <cstdlib> // Include for using rand() function
#include <ctime> // Include for using time() function
#include <cmath> // Include for mathematical functions like round()
#include <string>
#include <vector>
#include "Character.h"

using namespace std;

// Constructor to initialize character's attributes
Character::Character()
{
    attack = 10;
    defense = 2;
    gold = 0;
    level = 1;
    max_hp = 100;
    curr_hp = 100;
    max_mp = 20;
    curr_mp = 20;
    max_exp = 100;
    curr_exp = 0;
    curr_position = { 0, 0 };
    move_history = { {0, 0} };
}

// Destructor for the Chatacter class
Character::~Character(){}

// Display current status of character
void Character::show_status()
{
    cout << endl;
    cout << "Level: " << level << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Gold: " << gold << endl;
    cout << "HP: " << curr_hp << " / " << max_hp << endl;
    cout << "MP: " << curr_mp << " / " << max_mp << endl;
    cout << "EXP: " << curr_exp << " / " << max_exp << endl;
    cout << endl;
}

// Display battle status of character
void Character::battle_status()
{
    cout << "================================" << endl;
    cout << "Character status" << endl;
    cout << "Level: " << level << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "HP: " << curr_hp << " / " << max_hp << endl;
    cout << "MP: " << curr_mp << " / " << max_mp << endl;
    cout << "EXP: " << curr_exp << " / " << max_exp << endl;
}

// Adjust character status based on shop interactions
void Character::shop_status(int choiceNum, int origin_hp, int origin_mp)
{
    cout << "================================" << endl;
    cout << "Character status" << endl;
    cout << "Level: " << level << endl;

    // Display changes in attributes after shopping
    if (choiceNum == 1) cout << "Attack: " << attack - 10 << " => " << attack << endl;
    else cout << "Attack: " << attack << endl;

    if (choiceNum == 2) cout << "Defense: " << defense - 5 << " => " << defense << endl;
    else cout << "Defense: " << defense << endl;

    if (choiceNum == 4) cout << "HP: " << origin_hp << " / " << max_hp << " => " << curr_hp << " / " << max_hp << endl;
    else cout << "HP: " << curr_hp << "/" << max_hp << endl;

    if (choiceNum == 5) cout << "MP: " << origin_mp << " / " << max_mp << " => " << curr_mp << " / " << max_mp << endl;
    else cout << "MP: " << curr_mp << "/" << max_mp << endl;

    if (choiceNum == 3) cout << "Exp: " << curr_exp - 300 << " / " << max_exp << " => " << curr_exp << " / " << max_exp << endl;
    else cout << "Attack: " << attack << endl;
}

// Modify attributes of character, handle changes in the shop
int Character::change_status(int value, char option, bool shop)
{
    if (shop == true)
    {
        int origin = 0;
        switch (option)
        {
        case 'a': attack += value; return 0;
        case 'd': defense += value; return 0;
        case 'e': curr_exp += value; return 0;
        case 'g': gold -= value; return 0;
        case 'h':
            origin = curr_hp;
            curr_hp = max_hp;
            return origin;
        case 'm':
            origin = curr_mp;
            curr_mp = max_mp;
            return origin;
        default:
            return origin;
        }
    }
    else
    {
        curr_hp -= value; // Subtract damage from HP
        return 0;
    }
}

// Random event function affecting character's status
void Character::random_act()
{
    cout << "Random encounter!\n" << endl;
    vector<string> option = { "lost", "restore", "gold", "nothing" };
    int index = rand() % 4; // Generate a random index for selecting an event

    // Execute effect based on random choice
    if (option[index] == "lost") {
        curr_hp = round(curr_hp * 0.7); // Lose 30% of current HP
        cout << "You lost HP..." << endl;
    }
    else if (option[index] == "restore") {
        curr_hp = round(curr_hp * 1.3); // Restore 30% of HP
        if (curr_hp > max_hp) curr_hp = max_hp; // Cap HP at maximum
        cout << "You restored HP" << endl;
    }
    else if (option[index] == "gold") {
        gold += 100; // Gain 100 gold
        cout << "You found 100 gold!" << endl;
    }
    else {
        cout << "Nothing happened..." << endl;
    }
    return;
}

// Various getter and action methods for character attributes and actions follow below
int Character::character_defense()
{
    return defense; // Return character's defense
}

int Character::character_curr_mp()
{
    return curr_mp; // Return current MP
}

int Character::character_curr_hp()
{
    return curr_hp; // Return current HP
}

int Character::character_gold()
{
    return gold; // Return amount of gold character has
}

// Basic attack function, reduces enemy defense from character attack
int Character::attack_basic(int defense)
{
    int damage = attack - defense;
    if (damage < 0) damage = 0; // Ensure damage isn't negative
    return damage;
}

// Skill attack function, stronger attack that costs MP
int Character::attack_skill(int defense)
{
    int damage = attack * 1.5 - defense;
    if (damage < 0) damage = 0;
    curr_mp -= 15; // Reduce MP by 15
    return damage;
}

// Elemental attack functions (fire, grass, water), with type advantages
int Character::attack_fire(char type, int defense)
{
    int damage = 0;
    if (type == 'G') // If enemy is of type Grass
    {
        damage = attack * 2 - defense; // Double damage against Grass
    }
    else
    {
        damage = attack - defense;
    }
    if (damage < 0) damage = 0;
    curr_mp -= 15;
    return damage;
}

int Character::attack_grass(char type, int defense)
{
    int damage = 0;
    if (type == 'W') // If enemy is of type Water
    {
        damage = attack * 2 - defense; // Double damage against Water
    }
    else
    {
        damage = attack - defense;
    }
    if (damage < 0) damage = 0;
    curr_mp -= 15;
    return damage;
}

int Character::attack_water(char type, int defense)
{
    int damage = 0;
    if (type == 'F') // If enemy is of type Fire
    {
        damage = attack * 2 - defense; // Double damage against Fire
    }
    else
    {
        damage = attack - defense;
    }
    if (damage < 0) damage = 0;
    curr_mp -= 15;
    return damage;
}

// Reward system after defeating an enemy
void Character::character_reward(int reward)
{
    gold += reward; // Increase gold
    curr_exp += reward; // Increase experience

    level_up(true); // Check if the character levels up
}

// Check if experience exceeds max, indicating level up
bool Character::judge_level_up()
{
    if (curr_exp > max_exp) return true;
    else return false;
}

// Handle character leveling up
bool Character::level_up(bool print_option)
{
    int level_origin = level;
    int attack_origin = attack;
    int defense_origin = defense;
    int hp_origin = curr_hp;
    int mp_origin = curr_mp;
    int max_hp_origin = max_hp;
    int max_mp_origin = max_mp;
    int exp_origin = curr_exp;
    int max_exp_origin = max_exp;

    if (judge_level_up() == true)
    {
        while (judge_level_up() == true)
        {
            level += 1; // Increment level
            curr_exp = curr_exp - max_exp; // Subtract max exp from current exp
            max_exp = level * 100; // Increase max exp based on level
            attack += 3; // Increase attack
            defense += 1; // Increase defense
            max_hp += 50; // Increase max HP
            max_mp += 10; // Increase max MP
            curr_hp = max_hp; // Reset current HP to max
            curr_mp = max_mp; // Reset current MP to max
        }
        if (print_option == true) // If printing is enabled
        {
            cout << "Level up!" << endl;
            cout << "================================" << endl;
            cout << "Character status" << endl;
            cout << "Level: " << level_origin << " => " << level << endl;
            cout << "Attack: " << attack_origin << " => " << attack << endl;
            cout << "Defense: " << defense_origin << " => " << defense << endl;
            cout << "HP: " << hp_origin << " / " << max_hp_origin << " => " << curr_hp << " / " << max_hp << endl;
            cout << "MP: " << mp_origin << " / " << max_mp_origin << " => " << curr_mp << " / " << max_mp << endl;
            cout << "EXP: " << exp_origin << " / " << max_exp_origin << " => " << curr_exp << " / " << max_exp << endl;
            cout << "================================" << endl;
        }
        return true;
    }
    return false;
}
