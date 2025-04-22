#ifndef QUEUE_H
#define QUEUE_H

// Queue class template
template <typename T>
class Queue {
private:
    struct Node {
        T data;    // Data of the node
        Node* next;  // Pointer to the next node
        Node(T val) : data(val), next(nullptr) {}  // Constructor to initialize node
    };
    Node* frontNode;  // Pointer to the front node
    Node* rearNode;   // Pointer to the rear node
    int count;        // Number of elements in the queue

public:
    Queue();              // Constructor to initialize an empty queue
    ~Queue();             // Destructor to clean up memory
    void push(T val);     // Method to add an element to the queue
    void pop();           // Method to remove an element from the queue
    T front();            // Method to get the front element
    int size();           // Method to get the size of the queue
    bool empty();         // Method to check if the queue is empty
    void move_to_rear();  // Method to move the front element to the rear of the queue
};

#endif
