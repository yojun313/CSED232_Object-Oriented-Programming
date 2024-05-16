// main.cpp
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Map.h"
#include "Character.h"
#include "Battle.h"
#include "shop.h"

// Function declaration for selecting main menu option
int option_select();

// Main function: Entry point of the program
int main()
{
    srand(time(NULL)); // Seed random number generator based on current time
    using namespace std;

    // Create instances of Map, Character, and Shop
    Map myMap;
    Character myCharacter;
    Shop myShop;

    while (true)
    {
        int optionNum = option_select(); // Main menu option selection

        if (optionNum == 1)
        {
            cout << "Game start!\n" << endl;

            while (true)
            {
                myMap.draw_map(&myCharacter); // Draw the current state of the map
                int map_optionNum = myMap.map_option_select(); // Get map option selection

                // Choose Direction
                if (map_optionNum == 1)
                {
                    char place = myMap.map_move(&myCharacter); // Move character and get type of new place

                    // Actions based on the type of place encountered
                    if (place == 'E' || place == 'N'); // Empty or already visited: do nothing

                    else if (place == 'R') // Random event
                    {
                        myMap.draw_map(&myCharacter);
                        myCharacter.random_act(); // Trigger a random action
                    }

                    else if (place == 'M') // Monster or Boss fight
                    {
                        myMap.draw_map(&myCharacter);
                        Monster myMonster(myCharacter.curr_position, false); // Create a normal monster
                        Battle myBattle(&myCharacter, &myMonster);
                        char result = myBattle.battle_action(&myCharacter, &myMonster);

                        if (result == 'M') return 0; // If character loses, end the game
                    }

                    else if (place == 'B') // Boss fight, note this block should not be here as it's already handled above
                    {
                        myMap.draw_map(&myCharacter);
                        Monster myMonster(myCharacter.curr_position, true); // Create a boss monster
                        Battle myBattle(&myCharacter, &myMonster);
                        char result = myBattle.battle_action(&myCharacter, &myMonster);

                        if (result == 'C') // If character wins the boss fight
                        {
                            cout << "Congratulations! You cleared game" << endl;
                            return 0; // End the game
                        }
                        else
                        {
                            return 0; // End the game on loss
                        }
                    }

                    else if (place == 'S') // Shop
                    {
                        myMap.draw_map(&myCharacter);
                        myShop.shop_choice(&myCharacter); // Display shop and handle transactions
                    }
                }
                // Show character status
                else if (map_optionNum == 2)
                {
                    myCharacter.show_status(); // Display current status of character
                }
                // Exit Game
                else
                {
                    cout << "Exit..." << endl;
                    return 0; // Exit the game
                }
            }
        }
        else
        {
            cout << "Exit..." << endl;
            return 0; // Exit the game if the option chosen is not to start the game
        }
    }

    return 0;
}

// Function for selecting an option from the main menu
int option_select()
{
    using namespace std;
    cout << "========================================================" << endl;
    cout << "========================================================" << endl;
    cout << "========================================================" << endl;
    cout << " #######                      ######  ######   ##### " << endl;
    cout << "    #    ###### #    # #####  #     # #     # #     # " << endl;
    cout << "    #    #       #  #    #    #     # #     # # " << endl;
    cout << "    #    #####    ##     #    ######  ######  #  #### " << endl;
    cout << "    #    #        ##     #    #   #   #       #     #" << endl;
    cout << "    #    #       #  #    #    #    #  #       #     # " << endl;
    cout << "    #    ###### #    #   #    #     # #        ##### " << endl;
    cout << "========================================================" << endl;
    cout << "========================================================" << endl;
    cout << "========================================================" << endl;
    cout << "\n\n----- Menu -----" << endl;
    cout << "1. Start game" << endl;
    cout << "2. Exit" << endl;

    int optionNum = 0;
    while (true)
    {
        cout << "> ";
        cin >> optionNum; // Read user input
        if (optionNum == 1 || optionNum == 2) return optionNum; // Validate input and return
    }
}
