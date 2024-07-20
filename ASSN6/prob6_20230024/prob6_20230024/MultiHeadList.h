#pragma once
#ifndef MULTIHEADLIST_H
#define MULTIHEADLIST_H

#include <vector>
#include <string>

using namespace std;

// Node structure: Represents a node in the list.
template <typename T>
struct Node {
    T data;     // Data stored in the node
    Node* prev; // Pointer to the previous node
    Node* next; // Pointer to the next node

    // Constructor: Initializes the node with the given data.
    Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
};

// MultiHeadList class: Manages a list with multiple heads.
template <typename T>
class MultiHeadList {
private:
    vector<Node<T>*> headList; // Vector storing the head nodes of each list

public:
    // Iterator class: An iterator to traverse the list.
    class Iterator {
    private:
        Node<T>* curr; // Pointer to the current node
    public:
        // Constructor: Initializes the iterator with a given node.
        Iterator(Node<T>* node = nullptr) : curr(node) {}

        // Dereference operator: Returns the data of the current node.
        T& operator*() {
            return curr->data;
        }

        // Pre-increment operator: Moves to the next node.
        Iterator& operator++() {
            if (curr) curr = curr->next;
            return *this;
        }

        // Post-increment operator: Moves to the next node.
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        // Pre-decrement operator: Moves to the previous node.
        Iterator& operator--() {
            if (curr) curr = curr->prev;
            return *this;
        }

        // Post-decrement operator: Moves to the previous node.
        Iterator operator--(int) {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        // Addition operator: Moves the iterator forward by n positions.
        Iterator operator+(int n) const {
            Iterator temp = *this;
            for (int i = 0; i < n && temp.curr; ++i) {
                ++temp;
            }
            return temp;
        }

        // Subtraction operator: Moves the iterator backward by n positions.
        Iterator operator-(int n) const {
            Iterator temp = *this;
            for (int i = 0; i < n && temp.curr; ++i) {
                --temp;
            }
            return temp;
        }

        // Inequality operator: Checks if two iterators are not equal.
        bool operator!=(const Iterator& other) const {
            return curr != other.curr;
        }

        // Equality operator: Checks if two iterators are equal.
        bool operator==(const Iterator& other) const {
            return curr == other.curr;
        }

        // Returns the pointer to the current node.
        Node<T>* getNode() const {
            return curr;
        }
    };

    // ReverseIterator class: An iterator to traverse the list in reverse.
    class ReverseIterator {
    private:
        Node<T>* curr; // Pointer to the current node
    public:
        // Constructor: Initializes the iterator with a given node.
        ReverseIterator(Node<T>* node = nullptr) : curr(node) {}

        // Dereference operator: Returns the data of the current node.
        T& operator*() {
            return curr->data;
        }

        // Pre-increment operator: Moves to the previous node.
        ReverseIterator& operator++() {
            if (curr) curr = curr->prev;
            return *this;
        }

        // Post-increment operator: Moves to the previous node.
        ReverseIterator operator++(int) {
            ReverseIterator temp = *this;
            ++(*this);
            return temp;
        }

        // Pre-decrement operator: Moves to the next node.
        ReverseIterator& operator--() {
            if (curr) curr = curr->next;
            return *this;
        }

        // Post-decrement operator: Moves to the next node.
        ReverseIterator operator--(int) {
            ReverseIterator temp = *this;
            --(*this);
            return temp;
        }

        // Addition operator: Moves the iterator backward by n positions.
        ReverseIterator operator+(int n) const {
            ReverseIterator temp = *this;
            for (int i = 0; i < n && temp.curr; ++i) {
                ++temp;
            }
            return temp;
        }

        // Subtraction operator: Moves the iterator forward by n positions.
        ReverseIterator operator-(int n) const {
            ReverseIterator temp = *this;
            for (int i = 0; i < n && temp.curr; ++i) {
                --temp;
            }
            return temp;
        }

        // Inequality operator: Checks if two iterators are not equal.
        bool operator!=(const ReverseIterator& other) const {
            return curr != other.curr;
        }

        // Equality operator: Checks if two iterators are equal.
        bool operator==(const ReverseIterator& other) const {
            return curr == other.curr;
        }

        // Returns the pointer to the current node.
        Node<T>* getNode() const {
            return curr;
        }
    };

    // Returns the number of head nodes in the list.
    int headSize() const {
        return headList.size();
    }

    // Adds a new node with the given data at the end of the specified list.
    void push_back(const T& data, int headIdx = -1) {
        if (headIdx < 0 || headIdx >= headList.size()) {
            Node<T>* newNode = new Node<T>(data);
            headList.push_back(newNode);
        }
        else {
            Node<T>* tail = headList[headIdx];
            while (tail->next) {
                tail = tail->next;
            }
            Node<T>* newNode = new Node<T>(data);
            tail->next = newNode;
            newNode->prev = tail;
        }
    }

    // Adds a new node with the given data at the beginning of the specified list.
    void push_front(const T& data, int headIdx = -1) {
        if (headIdx < 0 || headIdx >= headList.size()) {
            Node<T>* newNode = new Node<T>(data);
            headList.push_back(newNode);
        }
        else {
            Node<T>* head = headList[headIdx];
            Node<T>* newNode = new Node<T>(data);
            newNode->next = head;
            head->prev = newNode;
            headList[headIdx] = newNode;
        }
    }

    // Inserts a new node with the given data before the specified position.
    void insert(Iterator pos, const T& data) {
        Node<T>* currNode = pos.getNode();
        if (currNode == nullptr) return;

        Node<T>* newNode = new Node<T>(data);
        newNode->next = currNode;
        newNode->prev = currNode->prev;
        if (currNode->prev) {
            currNode->prev->next = newNode;
        }
        else {
            for (auto& head : headList) {
                if (head == currNode) {
                    head = newNode;
                    break;
                }
            }
        }
        currNode->prev = newNode;
    }

    // Removes the last node of the specified list.
    void pop_back(int headIdx) {
        if (headIdx >= 0 && headIdx < headList.size()) {
            Node<T>* tail = headList[headIdx];
            if (!tail) return;
            while (tail->next) {
                tail = tail->next;
            }
            if (tail->prev) {
                tail->prev->next = nullptr;
            }
            else {
                headList[headIdx] = nullptr;
            }
            delete tail;
            if (headList[headIdx] == nullptr) {
                headList.erase(headList.begin() + headIdx);
            }
        }
    }

    // Removes the first node of the specified list.
    void pop_front(int headIdx) {
        if (headIdx >= 0 && headIdx < headList.size()) {
            Node<T>* head = headList[headIdx];
            if (!head) return;
            if (head->next) {
                headList[headIdx] = head->next;
                head->next->prev = nullptr;
            }
            else {
                headList[headIdx] = nullptr;
            }
            delete head;
            if (headList[headIdx] == nullptr) {
                headList.erase(headList.begin() + headIdx);
            }
        }
    }

    // Merges the list at backHeadIdx into the list at frontHeadIdx.
    void merge(int frontHeadIdx, int backHeadIdx) {
        if (frontHeadIdx >= 0 && frontHeadIdx < headList.size() &&
            backHeadIdx >= 0 && backHeadIdx < headList.size()) {
            Node<T>* frontTail = headList[frontHeadIdx];
            if (!frontTail) return;
            while (frontTail->next) {
                frontTail = frontTail->next;
            }
            frontTail->next = headList[backHeadIdx];
            if (headList[backHeadIdx]) {
                headList[backHeadIdx]->prev = frontTail;
            }
            headList[backHeadIdx] = nullptr; // Clear the merged list's head
            headList.erase(headList.begin() + backHeadIdx);
        }
    }

    // Erases the node with the specified data in the specified list.
    bool erase(const T& data, int targetHeadIdx) {
        if (targetHeadIdx >= 0 && targetHeadIdx < headList.size()) {
            Node<T>* curr = headList[targetHeadIdx];
            while (curr) {
                if (curr->data == data) {
                    if (curr->prev) {
                        curr->prev->next = curr->next;
                    }
                    else {
                        headList[targetHeadIdx] = curr->next;
                    }
                    if (curr->next) {
                        curr->next->prev = curr->prev;
                    }
                    delete curr;
                    if (headList[targetHeadIdx] == nullptr) {
                        headList.erase(headList.begin() + targetHeadIdx);
                    }
                    return true;
                }
                curr = curr->next;
            }
        }
        return false;
    }
  
    // Erases the node at the specified iterator position.
    bool erase(Iterator pos) {
        Node<T>* curr = pos.getNode();
        if (curr == nullptr) return false;

        Node<T>* nextNode = curr->next;

        // Update the previous node's next pointer
        if (curr->prev) {
            curr->prev->next = curr->next;
        }
        else {
            // Update the head if current node is the head
            for (auto& head : headList) {
                if (head == curr) {
                    head = curr->next;
                    break;
                }
            }
        }

        // Update the next node's prev pointer
        if (curr->next) {
            curr->next->prev = curr->prev;
        }

        // If there's a next node, add it as a new head
        if (nextNode) {
            headList.push_back(nextNode);
            nextNode->prev->next = nullptr; // Break the link from the previous part of the list
            nextNode->prev = nullptr;       // Ensure the new head has no previous node
        }

        delete curr;

        // Ensure the headList does not have nullptr entries
        headList.erase(remove(headList.begin(), headList.end(), nullptr), headList.end());

        return true;
    }

    bool rremove(Iterator pos) {
        Node<T>* curr = pos.getNode();
        if (curr == nullptr) return false;

        // Update the previous node's next pointer
        if (curr->prev) {
            curr->prev->next = curr->next;
        }
        else {
            // Update the head if current node is the head
            for (auto& head : headList) {
                if (head == curr) {
                    head = curr->next;
                    break;
                }
            }
        }

        // Update the next node's prev pointer
        if (curr->next) {
            curr->next->prev = curr->prev;
        }

        // Delete the current node
        delete curr;

        // Remove nullptr entries from headList
        headList.erase(remove(headList.begin(), headList.end(), nullptr), headList.end());

        return true;
    }

    // Returns an iterator to the beginning of the specified list.
    Iterator begin(int headIdx) {
        if (headIdx >= 0 && headIdx < headList.size()) {
            return Iterator(headList[headIdx]);
        }
        return end();
    }

    // Returns an iterator to the end of the list (null).
    Iterator end() {
        return Iterator(nullptr);
    }

    // Returns a reverse iterator to the beginning of the specified list.
    ReverseIterator rbegin(int headIdx) {
        if (headIdx >= 0 && headIdx < headList.size()) {
            Node<T>* tail = headList[headIdx];
            if (!tail) return rend();
            while (tail->next) {
                tail = tail->next;
            }
            return ReverseIterator(tail);
        }
        return rend();
    }

    // Returns a reverse iterator to the end of the list (null).
    ReverseIterator rend() {
        return ReverseIterator(nullptr);
    }

    // Finds the index of the specified iterator in the headList.
    int findIndex(Iterator pos) const {
        Node<T>* curr = pos.getNode();
        for (int i = 0; i < headList.size(); ++i) {
            Node<T>* node = headList[i];
            while (node) {
                if (node == curr) return i;
                node = node->next;
            }
        }
        return -1; // Not found
    }
};

#endif
