#ifndef PROB2_H

typedef struct Node
{
    int value = 0;
    struct Node* next = 0x00;
} Node;

typedef struct _OrderedSet
{
    int m_size = 0;
    Node* head;
} OrderedSet;

void add(OrderedSet* ordered, int v);

void add(OrderedSet* ordered, const int* arr, int size);

void remove(OrderedSet* ordered, int index);

int size(OrderedSet* ordered);

bool contains(OrderedSet* ordered, int v);

int getValue(OrderedSet* ordered, int idx);

#endif

