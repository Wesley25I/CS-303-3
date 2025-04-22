#include <iostream>
#include <vector>
#include "queue.h"       
#include "LinkedList.h"  
using namespace std;

// Function to find the last occurrence of a target in a vector (recursive)
int recursive_last_search(const vector<int>& vec, int target, int index) {
    if (index < 0) return -1;  // Base case: if index goes below 0, not found
    if (vec[index] == target) return index;  // If target is found, return the index
    return recursive_last_search(vec, target, index - 1);  // Recursively search earlier elements
}

int main() {
   
    Queue<int> q;  // Create a Queue of integers
    for (int i = 1; i <= 10; i++) q.push(i * 10);  // Push values into the queue

    // Display all elements in the queue
    cout << "Queue elements: ";
    int n = q.size();
    for (int i = 0; i < n; i++) {
        cout << q.front() << " ";  // Print front element
        q.move_to_rear();  // Move front element to rear
    }
    cout << endl;

    // Test move_to_rear function
    cout << "Before move_to_rear: Front = " << q.front() << endl;
    q.move_to_rear();
    cout << "After move_to_rear: New Front = " << q.front() << endl;

   
    vector<int> data = {5, 3, 7, 3, 9, 3};
    int target = 3;  // Target value to search for
    int lastPos = recursive_last_search(data, target, data.size() - 1);  // Call the recursive search
    cout << (lastPos != -1 ? "Last occurrence at index: " + to_string(lastPos) : "Not found!") << endl;

    // Q3: LinkedList Insertion Sort
    LinkedList list;  // Create a LinkedList
    list.insert(20);  // Add values to the list
    list.insert(65);
    list.insert(30);
    list.insert(10);

    // Display list before sorting
    cout << "Before Sorting: ";
    list.display();

    // Sort the linked list using insertion sort
    list.insertionSort();

    // Display list after sorting
    cout << "After Sorting: ";
    list.display();

    return 0;  // End of program
}
