#pragma once
#include <iostream>

using namespace std;

// uses template so the linked list can contain many data types
template<typename Item_Type>
// Creates the linked list class
class Single_Linked_List {
private:
    // defines the structure of the nodes in the list
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    // Constructor for the linked list
    Single_Linked_List();
    // returns the num_items data member
    size_t size() const;
    // Makes a new node and then adjusts node pointers and increments num_items (front)
    void push_front(const Item_Type& item);
    // Also makes a new node then adjusts node pointers and increments num_items (back)
    void push_back(const Item_Type& item);
    // removes the item from the front by moving the head node to the next node
    // deletes the popped node and decrements num_items
    void pop_front();
    // removes the item from the back by moving the tail node to the previous node
    // deletes the popped node and decrements num_items
    void pop_back();
    // returns the data at the front node (head)
    Item_Type front() const;
    // returns the data at the last node (tail)
    Item_Type back() const;
    // returns bool if num_items is 0 (list is empty)
    bool empty() const;
    // uses the push back and front functions if user requests to put a node at the front or back
    // otherwise creates a new node and traverses the list until the desired index
    // once it reaches desired index it adjusts the pointers to insert the node
    // increment num_items
    void insert(size_t index, const Item_Type& item);
    // if the index is zero, uses pop front, else it traverses the list to the desired index
    // once at the desired index it adjust the pointers to effectively remove the node
    // also deletes the old node to free up memory
    // decrements num_items
    bool remove(size_t index);
    // traverses the list until finding the desired item and returns the index of the item
    // otherwise returns num_items
    size_t find(const Item_Type& item) const;
    // iterates through the list to print the list using a while loop
    void printList() const;
};
