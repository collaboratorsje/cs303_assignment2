#pragma once
#include "Single_Linked_List.h"

// Constructor for the linked list
template<typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// returns the num_items data member
template<typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;
}
// Makes a new node and then adjusts node pointers and increments num_items (front)
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    num_items++;
}
// Also makes a new node then adjusts node pointers and increments num_items (back)
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}
// removes the item from the front by moving the head node to the next node
// deletes the popped node and decrements num_items
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        cout << "Error: List is empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) {
        tail = nullptr;
    }

    num_items--;
}
// removes the item from the back by moving the tail node to the previous node
// deletes the popped node and decrements num_items
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) {
        cout << "Error: List is empty." << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    num_items--;
}
// returns the data at the front node (head)
template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (empty()) {
        cout << "Error: List is empty." << endl;
        return Item_Type();
    }
    return head->data;
}
// returns the data at the last node (tail)
template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (empty()) {
        cout << "Error: List is empty." << endl;
        return Item_Type();
    }
    return tail->data;
}
// returns bool if num_items is 0 (list is empty)
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}
// uses the push back and front functions if user requests to put a node at the front or back
// otherwise creates a new node and traverses the list until the desired index
// once it reaches desired index it adjusts the pointers to insert the node
// increment num_items
template<typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index >= num_items) {
        push_back(item);
        return;
    }

    if (index == 0) {
        push_front(item);
        return;
    }

    Node* new_node = new Node(item);
    Node* current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    num_items++;
}
// if the index is zero, uses pop front, else it traverses the list to the desired index
// once at the desired index it adjust the pointers to effectively remove the node
// also deletes the old node to free up memory
// decrements num_items
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (empty() || index >= num_items) {
        return false;
    }

    if (index == 0) {
        pop_front();
        return true;
    }

    Node* current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    num_items--;

    if (current->next == nullptr) {
        tail = current;
    }

    return true;
}
// traverses the list until finding the desired item and returns the index of the item
// otherwise returns num_items
template<typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* current = head;
    size_t index = 0;

    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }

        current = current->next;
        index++;
    }

    return num_items;
}
// iterates through the list to print the list using a while loop
template<typename Item_Type>
void Single_Linked_List<Item_Type>::printList() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

