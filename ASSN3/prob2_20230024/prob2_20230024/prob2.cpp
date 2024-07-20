#include "prob2.h"
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    return 0;
}

// Function to add a value to the ordered set
void add(OrderedSet* ordered, int v)
{
    Node* newNode = new Node; // Create a new node
    newNode->value = v; // Assign the value to the new node

    // If the ordered set is empty
    if (ordered->m_size == 0)
    {
        ordered->head = newNode; // Set the new node as the head
        ordered->m_size++; // Increment the size
        return;
    }
    else
    {
        Node* current = ordered->head;
        // Iterate through the list to check if the value already exists
        for (int i = 0; i < ordered->m_size; i++)
        {
            if (v == current->value) // If the value exists, do not add it
            {
                return;
            }
            current = current->next;
        }
    }

    // If the new node's value is smaller than or equal to the head's value, insert it at the beginning
    if (v <= ordered->head->value)
    {
        newNode->next = ordered->head;
        ordered->head = newNode;
        ordered->m_size++;
    }
    else
    {
        Node* current = ordered->head;
        // Iterate to the last node
        for (int i = 0; i < ordered->m_size - 1; i++)
        {
            current = current->next;
        }
        // If the new node's value is greater than all existing nodes' values, insert it at the end
        if (v >= current->value)
        {
            current->next = newNode;
            ordered->m_size++;
        }
        else
        {
            // If the new node's value is between two nodes' values, find the correct position
            current = ordered->head;
            while (true)
            {
                if (v >= current->value && v <= current->next->value)
                {
                    newNode->next = current->next;
                    current->next = newNode;
                    ordered->m_size++;
                    break;
                }
                current = current->next;
            }
        }

    }
}

// Function to add multiple values from an array to the ordered set
void add(OrderedSet* ordered, const int* arr, int size)
{
    // Iterate through the array and add each value using the add function
    for (int i = 0; i < size; i++)
    {
        add(ordered, arr[i]);
    }
}

// Function to remove a node at a specified index from the ordered set
void remove(OrderedSet* ordered, int index)
{
    Node* current = ordered->head;
    // Iterate to the node just before the target node
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    // Remove the target node by skipping it in the linked list
    current->next = current->next->next;
    ordered->m_size--; // Decrement the size
}

// Function to return the size of the ordered set
int size(OrderedSet* ordered)
{
    return ordered->m_size;
}

// Function to check if the ordered set contains a given value
bool contains(OrderedSet* ordered, int v)
{
    Node* current = ordered->head;
    bool check = false;

    // Iterate through the list to check if the value exists
    for (int i = 0; i < ordered->m_size - 1; i++)
    {
        if (current->value == v)
        {
            check = true;
        }
        current = current->next;
    }
    return check;
}

// Function to get the value of a node at a specified index in the ordered set
int getValue(OrderedSet* ordered, int idx)
{
    // Return a minimum integer if the index is invalid or the set is empty
    if (ordered->m_size == 0 or idx > ordered->m_size - 1)
    {
        return std::numeric_limits<int>::min();
    }

    Node* current = ordered->head;
    // Iterate to the target node
    for (int i = 0; i < idx; i++)
    {
        current = current->next;
    }
    return current->value; // Return the value of the target node
}
