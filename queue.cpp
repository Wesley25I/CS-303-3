#include <iostream>
#include "queue.h" 

using namespace std;

template <typename T>
Queue<T>::Queue() {
    frontNode = nullptr;
    rearNode = nullptr;
    count = 0;
}

template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();  // Pop elements until the queue is empty
    }
}

template <typename T>
void Queue<T>::push(T val) {
    Node* newNode = new Node(val);  // Create a new node
    if (empty()) {
        frontNode = rearNode = newNode;  // If the queue is empty, set both front and rear to the new node
    } else {
        rearNode->next = newNode;  // Otherwise, add the new node to the rear
        rearNode = newNode;  // Update the rear to the new node
    }
    count++;  // Increment the size of the queue
}

template <typename T>
void Queue<T>::pop() {
    if (!empty()) {
        Node* temp = frontNode;  // Save the front node
        frontNode = frontNode->next;  // Move the front pointer to the next node
        delete temp;  // Delete the old front node
        count--;  // Decrement the size of the queue
        if (frontNode == nullptr) rearNode = nullptr;  // If the queue becomes empty, reset the rear pointer
    }
}

template <typename T>
T Queue<T>::front() {
    if (!empty()) {
        return frontNode->data;  // Return the data at the front of the queue
    }
    throw runtime_error("Queue is empty");  // If empty, throw an error
}

template <typename T>
int Queue<T>::size() {
    return count;  // Return the current size of the queue
}

template <typename T>
bool Queue<T>::empty() {
    return count == 0;  // Return true if the queue is empty
}

template <typename T>
void Queue<T>::move_to_rear() {
    if (!empty()) {
        T temp = front();  // Get the front element
        pop();  // Remove it from the front
        push(temp);  // Add it back to the rear
    }
}

// Explicit instantiations
template class Queue<int>;
template class Queue<float>;
template class Queue<string>;
