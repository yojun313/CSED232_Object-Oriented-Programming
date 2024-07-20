#include "prob1.h"
#include <iostream>
#include <limits>

using namespace std;


void simpleTest1(OrderedList* o) {
    add(o, 5);
    add(o, 4);
    add(o, 3);
    add(o, 80);
    add(o, 50);
    for (int i = 0; i < o->m_size; ++i) {
        std::cout << getValue(o, i) << ", ";
    }
    std::cout << std::endl;
}
void simpleTest2(OrderedList* o) {
    int vals[] = { 10, 20, 35, 35, 10 }; add(o, vals, sizeof(vals) / sizeof(int));
    for (int i = 0; i < o->m_size; ++i) {
        std::cout << getValue(o, i) << ", ";
    }
    std::cout << std::endl;
}
void simpleTest3(OrderedList* o) {
    remove(o, 0);
    for (int i = 0; i < o->m_size; ++i) {
        std::cout << getValue(o, i) << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    OrderedList orderedList;
    std::cout << "<<Simple Test 1>>" << std::endl; 
    simpleTest1(&orderedList);
    std::cout << "<<Simple Test 2>>" << std::endl; 
    simpleTest2(&orderedList);
    std::cout << "<<Simple Test 3>>" << std::endl; 
    simpleTest3(&orderedList);
}

void add(OrderedList* ordered, int v)
{
    Node* newNode = new Node;
    newNode->value = v;

    if (ordered->m_size == 0)
    {
        ordered->head = newNode;
        ordered->m_size++;
    }
    else
    {
        if (v <= ordered->head->value) // if new node is smaller than head node
        {
            newNode->next = ordered->head;
            ordered->head = newNode;
            ordered->m_size++;
        }
        else
        {
            Node* current = ordered->head; // if new node is largest
            for (int i = 0; i < ordered->m_size - 1; i++)
            {
                current = current->next;
            }

            if (v >= current->value)
            {
                current->next = newNode;
                ordered->m_size++;
            }
            else
            {
                current = ordered->head; // if new node is between two nodes
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
}

// Adds a single value to the ordered list in a sorted manner
void add(OrderedList* ordered, const int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        add(ordered, arr[i]); // Re-using the add function for single values
    }
}

// Removes a node at a specified index from the ordered list
void remove(OrderedList* ordered, int index)
{
    Node* current = ordered->head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next; // Finding the node before the one to be removed
    }
    current->next = current->next->next; // Removing the node by skipping it in the list
    ordered->m_size--;
}

// Returns the size of the ordered list
int size(OrderedList* ordered)
{
    return ordered->m_size;
}

// Checks if the ordered list contains a given value
bool contains(OrderedList* ordered, int v)
{
    Node* current = ordered->head;
    bool check = false;

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

// Returns the value of the node at a specified index in the ordered list
int getValue(OrderedList* ordered, int idx)
{
    if (ordered->m_size == 0 or idx > ordered->m_size - 1)
    {
        return std::numeric_limits<int>::min();
    }

    Node* current = ordered->head;
    for (int i = 0; i < idx; i++)
    {
        current = current->next;
    }

    return current->value;
}