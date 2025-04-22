#include <iostream>
#include "LinkedList.h"  // Include LinkedList class definition

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;  // Initialize an empty linked list (head points to null)
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;  // Save the current head
        head = head->next;  // Move head to the next node
        delete temp;        // Delete the old head
    }
}

void LinkedList::insert(int val) {
    Node* newNode = new Node(val);  // Create a new node with the given value
    newNode->next = head;           // Set the new node's next to the current head
    head = newNode;                 // Update head to the new node
}

void LinkedList::display() {
    Node* curr = head;  // Start from the head node
    while (curr != nullptr) {
        cout << curr->data << " ";  // Print the current node's data
        curr = curr->next;          // Move to the next node
    }
    cout << endl;  // End the list display with a newline
}

void LinkedList::insertionSort() {
    Node* sorted = nullptr;  // Start with an empty sorted list
    Node* current = head;    // Start with the original list

    while (current != nullptr) {
        Node* next = current->next;  // Save the next node
        if (!sorted || sorted->data >= current->data) {
            current->next = sorted;  // Insert at the front if sorted is empty or current is smaller
            sorted = current;        // Update the sorted list
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < current->data) {
                temp = temp->next;    // Find the position to insert
            }
            current->next = temp->next;  // Insert in the correct position
            temp->next = current;
        }
        current = next;  // Move to the next node
    }
    head = sorted;  // Update head to point to the sorted list
}
