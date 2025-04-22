#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
private:
    struct Node {
        int data;    // Data of the node
        Node* next;  // Pointer to the next node
        Node(int val) : data(val), next(nullptr) {}  // Constructor to initialize node
    };
    Node* head;  // Pointer to the first node of the list

public:
    LinkedList();         // Constructor to initialize an empty linked list
    ~LinkedList();        // Destructor to clean up memory
    void insert(int val); // Method to insert a value at the beginning
    void display();       // Method to display all elements in the list
    void insertionSort(); // Method to sort the list using insertion sort
};

#endif
