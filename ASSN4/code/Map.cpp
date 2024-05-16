// Map.cpp
#include "Map.h"
#include "Character.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// Constructor initializes the map with specific cell values representing different types of tiles
Map::Map() : map_info({
    {'E', 'R', 'M', 'M', 'R', 'E', 'M', 'M'},
    {'M', 'E', 'R', 'E', 'M', 'R', 'E', 'R'},
    {'R', 'M', 'E', 'E', 'M', 'E', 'M', 'M'},
    {'M', 'E', 'R', 'S', 'M', 'M', 'E', 'R'},
    {'M', 'M', 'E', 'R', 'E', 'R', 'M', 'E'},
    {'E', 'R', 'M', 'E', 'M', 'E', 'E', 'R'},
    {'M', 'E', 'R', 'M', 'M', 'E', 'R', 'M'},
    {'E', 'E', 'M', 'E', 'R', 'M', 'E', 'B'}
    }) {}

// Destructor for the Map class
Map::~Map() {}

// Function to draw the map showing the player's current position and visited tiles
void Map::draw_map(Character* myCharacter)
{
    int pX = myCharacter->curr_position[0]; // Player's current X position
    int pY = myCharacter->curr_position[1]; // Player's current Y position

    if (pX < 0 || pX > 7 || pY < 0 || pY > 7) {
        cout << "Invalid position for You" << endl;
        return;
    }

    // Draw the top border of the map
    cout << "忙式式式成式式式成式式式成式式式成式式式成式式式成式式式成式式式忖" << endl;

    // Draw each row of the map
    for (int y = 0; y < 8; y++) {
        cout << "弛";
        for (int x = 0; x < 8; x++) {
            bool isHistory = false; // Flag to check if the current tile has been visited
            for (auto& history : myCharacter->move_history) {
                if (history[0] == x && history[1] == y) {
                    isHistory = true;
                    break;
                }
            }

            if (x == pX && y == pY) {
                cout << "You弛"; // Indicate player's current position
            }
            else if (isHistory) {
                cout << "   弛"; // Indicate visited tiles
            }
            else {
                cout << " ? 弛"; // Indicate unvisited tiles
            }
        }
        cout << endl;

        // Draw row dividers
        if (y != 7) {
            cout << "戍式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式扣" << endl;
        }
    }

    // Draw the bottom border of the map
    cout << "戌式式式扛式式式扛式式式扛式式式扛式式式扛式式式扛式式式扛式式式戎" << endl;
}

// Function to display options for navigating the map and prompt for user input
int Map::map_option_select()
{
    cout << "1. Choose direction" << endl;
    cout << "2. Show character status" << endl;
    cout << "3. Exit game" << endl;

    int map_optionNum = 0;
    while (true)
    {
        cout << "> ";
        cin >> map_optionNum;
        if (map_optionNum == 1 || map_optionNum == 2 || map_optionNum == 3) return map_optionNum; // Ensure valid input
    }
}

// Function to move the character on the map and handle the logic of encountering different tiles
char Map::map_move(Character* myCharacter)
{
    cout << "Where do you want to go?" << endl;
    char move_key;
    while (true)
    {
        while (true)
        {
            cout << "> ";
            cin >> move_key;
            if (move_key == 'w' || move_key == 's' || move_key == 'a' || move_key == 'd') break; // Validate direction input
        }

        int curr_position_x = myCharacter->curr_position[0]; // Current x position
        int curr_position_y = myCharacter->curr_position[1]; // Current y position

        // Adjust position based on direction input
        if (move_key == 'w') curr_position_y -= 1;
        else if (move_key == 'a') curr_position_x -= 1;
        else if (move_key == 's') curr_position_y += 1;
        else if (move_key == 'd') curr_position_x += 1;

        vector<int> new_position = { curr_position_x, curr_position_y }; // New proposed position

        // Check if the new position is already visited
        auto find_history = find(myCharacter->move_history.begin(), myCharacter->move_history.end(), new_position);
        if (find_history != myCharacter->move_history.end())
        {
            myCharacter->curr_position = new_position; // Update position
            if (map_info[curr_position_y][curr_position_x] == 'S') return 'S'; // Shop encountered
            else return 'N'; // Nothing special, visited
        }

        if ((0 <= curr_position_x && curr_position_x <= 7) && (0 <= curr_position_y && curr_position_y <= 7))
        {
            myCharacter->curr_position = new_position; // Update position
            myCharacter->move_history.push_back(new_position); // Record new position as visited

            return map_info[curr_position_y][curr_position_x]; // Return the character at the new position
        }
        else
        {
            cout << "You cannot move to that direction." << endl; // Handle invalid movement
        }
    }
}
