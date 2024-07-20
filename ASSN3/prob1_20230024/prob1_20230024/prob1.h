#ifndef PROB1_H

typedef struct _Node
{
    int value = 0;
    struct _Node* next = 0x00;
} Node;

typedef struct _OrderedList
{
    int   m_size = 0;
    Node* head = 0x00;
} OrderedList;

void add(OrderedList* ordered, int v);

void add(OrderedList* ordered, const int* arr, int size);

void remove(OrderedList* ordered, int index);

int size(OrderedList* ordered);

bool contains(OrderedList* ordered, int v);

int getValue(OrderedList* ordered, int idx);

#endif
