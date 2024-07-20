#include <iostream>
#include <string>
#include "MultiHeadList.h"

using namespace std;

class Syllogism {
private:
    MultiHeadList<pair<string, string>> syl; // MultiHeadList to store pairs of syllogisms

    // Helper function to compare two strings
    bool stringEquals(const string& str1, const string& str2) {
        return str1 == str2;
    }

public:
    // Function to add a new syllogism
    void put(const pair<string, string>& argument) {
        // Check if the first part of the argument exists in any head
        for (int i = 0; i < syl.headSize(); ++i) {
            for (auto it = syl.begin(i); it != syl.end(); ++it) {
                if (stringEquals((*it).second, argument.first)) {
                    int index = syl.findIndex(it);
                    syl.push_back(argument, index); // Add argument to the end of the found list

                    // Connect remaining nodes
                    string lastSecond = argument.second;
                    bool connected = true;
                    while (connected) {
                        connected = false;
                        for (int j = 0; j < syl.headSize(); ++j) {
                            for (auto it2 = syl.begin(j); it2 != syl.end(); ++it2) {
                                if (stringEquals((*it2).first, lastSecond)) {
                                    syl.push_back(*it2, index); // Add it2 to the end of the list
                                    lastSecond = (*it2).second;
                                    connected = true;
                                    syl.rremove(it2); // Remove the list that was just connected
                                    break;
                                }
                            }
                            if (connected) break;
                        }
                    }
                    return;
                }
                else if (stringEquals((*it).first, argument.second)) {
                    int index = syl.findIndex(it);
                    syl.push_front(argument, index); // Add argument to the front of the found list

                    // Try to connect remaining nodes
                    string lastFirst = argument.first;
                    bool connected = true;
                    while (connected) {
                        connected = false;
                        for (int j = 0; j < syl.headSize(); ++j) {
                            for (auto it2 = syl.begin(j); it2 != syl.end(); ++it2) {
                                if (stringEquals((*it2).second, lastFirst)) {
                                    syl.push_front(*it2, index); // Add it2 to the front of the list
                                    lastFirst = (*it2).first;
                                    connected = true;
                                    syl.rremove(it2); // Remove the node that was just connected
                                    break;
                                }
                            }
                            if (connected) break;
                        }
                    }
                    return;
                }
            }
        }
        // If not found, create a new head
        syl.push_back(argument);
    }

    // Function to answer a question based on the syllogisms
    void qna(const string& q) {
        string result = q;
        bool found = false;

        // Iterate to find the initial match
        for (int i = 0; i < syl.headSize(); ++i) {
            for (auto it = syl.begin(i); it != syl.end(); ++it) {
                if (stringEquals((*it).first, result)) {
                    result = (*it).second;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (found) {
            // Follow the chain of reasoning
            string intermediateResult = result;
            for (int i = 0; i < syl.headSize(); ++i) {
                for (auto it = syl.begin(i); it != syl.end(); ++it) {
                    if (stringEquals((*it).first, intermediateResult)) {
                        result = (*it).second;
                        intermediateResult = result;
                        i = -1; // Restart the outer loop
                        break;
                    }
                }
            }
            cout << "If " << q << ", then " << result << endl;
        }
        else {
            cout << "No conclusion can be drawn from " << q << endl;
        }
    }

    // Function to print the current state of the syllogisms
    void print() {
        cout << "=============" << endl;
        for (int i = 0; i < syl.headSize(); ++i) {
            cout << i << " : ";
            for (auto it = syl.begin(i); it != syl.end(); ++it) {
                if (it == syl.begin(i)) {
                    cout << (*it).first << "->" << (*it).second;
                }
                else {
                    cout << "->" << (*it).second;
                }
            }
            cout << endl;
        }
    }
};
