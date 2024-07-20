// Shop.cpp
#include "Shop.h"
#include <iostream>
#include "Character.h"

using namespace std;

// Constructor for the Shop class
Shop::Shop()
{
    plus_attack = 1; // Initialize attack upgrade availability
    plus_defense = 1; // Initialize defense upgrade availability
    plus_exp = 1; // Initialize experience upgrade availability
}

// Destructor for the Shop class

Shop::~Shop() {}

// Function to display available shop products
void Shop::shop_product(int choiceNum)
{
    cout << "1. Attack +10 (700 Gold) "; // Display attack product
    if (choiceNum == 1) // If selected
    {
        cout << "(Available) => (Sold Out)" << endl; // Indicate sold out if selected
    }
    else
    {
        if (plus_attack > 0) cout << "(Available)" << endl; // Show availability based on stock
        else cout << "(Sold Out)" << endl; // Show sold out if out of stock
    }

    cout << "2. Defense +5 (700 Gold) "; // Display defense product
    if (choiceNum == 2) // If selected
    {
        cout << "(Available) => (Sold Out)" << endl;
    }
    else
    {
        if (plus_defense > 0) cout << "(Available)" << endl;
        else cout << "(Sold Out)" << endl;
    }

    cout << "3. Exp +300 (700 Gold) "; // Display experience product
    if (choiceNum == 3) // If selected
    {
        cout << "(Available) => (Sold Out)" << endl;
    }
    else
    {
        if (plus_exp > 0) cout << "(Available)" << endl;
        else cout << "(Sold Out)" << endl;
    }

    cout << "4. Restore HP (500 Gold) (Always available)" << endl; // HP restoration is always available
    cout << "5. Restore MP (500 Gold) (Always available)" << endl; // MP restoration is always available
    cout << "6. Exit shop" << endl; // Option to exit shop
}

// Function to handle the interaction in the shop
void Shop::shop_choice(Character* myCharacter)
{
    int character_gold = myCharacter->character_gold(); // Get current gold from character

    cout << "Welcome to the item shop!" << endl;
    cout << "You have " << character_gold << " Gold." << endl;

    // Display shop products
    cout << "=================================" << endl;
    cout << "=========== Item list ===========" << endl;
    cout << "=================================\n" << endl;
    shop_product(0); // Display all products initially
    cout << "\n=================================" << endl;

    int choiceNum = 0;
    int success = 0;
    int origin_hp = 0;
    int origin_mp = 0;
    while (true)
    {
        if (success == 1 or success == 2) break; // Break loop if transaction is successful or exit is chosen

        cout << "> ";
        cin >> choiceNum;

        // Handle choice input
        if (choiceNum >= 1 && choiceNum <= 6)
        {
            switch (choiceNum)
            {
            case 1: // Attack upgrade
                if (plus_attack > 0 && character_gold >= 700)
                {
                    myCharacter->change_status(10, 'a', true); // Apply attack bonus
                    myCharacter->change_status(700, 'g', true); // Deduct cost
                    plus_attack -= 1; // Decrement stock
                    success = 1;
                }
                else if (plus_attack <= 0) cout << "Selected item is not available...\n" << endl;
                else cout << "You do not have enough gold...\n" << endl;
                break;

            case 2: // Defense upgrade
                if (plus_defense > 0 && character_gold >= 700)
                {
                    myCharacter->change_status(5, 'd', true);
                    myCharacter->change_status(700, 'g', true);
                    plus_defense -= 1;
                    success = 1;
                }
                else if (plus_defense <= 0) cout << "Selected item is not available...\n" << endl;
                else cout << "You do not have enough gold...\n" << endl;
                break;

            case 3: // Experience upgrade
                if (plus_exp > 0 && character_gold >= 700)
                {
                    myCharacter->change_status(300, 'e', true);
                    myCharacter->change_status(700, 'g', true);
                    plus_exp -= 1;
                    success = 1;
                }
                else if (plus_exp <= 0) cout << "Selected item is not available...\n" << endl;
                else cout << "You do not have enough gold...\n" << endl;
                break;

            case 4: // HP restoration
                if (character_gold >= 500)
                {
                    origin_hp = myCharacter->change_status(0, 'h', true);
                    myCharacter->change_status(500, 'g', true);
                    success = 1;
                }
                else cout << "You do not have enough gold...\n" << endl;
                break;

            case 5: // MP restoration
                if (character_gold >= 500)
                {
                    origin_mp = myCharacter->change_status(0, 'm', true);
                    myCharacter->change_status(500, 'g', true);
                    success = 1;
                }
                else cout << "You do not have enough gold...\n" << endl;
                break;

            case 6: // Exit shop
                success = 2;
                break;
            }
        }
    }
    // Post transaction processes
    if (success == 1)
    {
        cout << "\nYou bought an item!\n" << endl;

        if (myCharacter->judge_level_up() == true) // Check if the transaction results in a level up
        {
            myCharacter->level_up(true); // Process level up
        }
        else
        {
            myCharacter->shop_status(choiceNum, origin_hp, origin_mp); // Update status in shop context
        }

        cout << "================================" << endl;
        cout << "Shop item list" << endl;
        shop_product(choiceNum); // Refresh the product list after transaction
        cout << "================================" << endl;
    }
    else
    {
        return; // Exit without further action
    }
}
