#include <iostream>
#include <queue>

using namespace std;

class Queue {
private:
    queue<int> q;

public:
    // Check if the queue is empty
    bool isEmpty() {
        return q.empty();
    }

    // Get the total number of elements in the queue
    int getSize() {
        return q.size();
    }

    // Add an element to the back of the queue
    void enqueue(int value) {
        q.push(value);
    }

    // Remove the front element from the queue
    void dequeue() {
        if (!q.empty()) {
            q.pop();
        }
    }

    // Get the value of the front element
    int front() {
        if (!q.empty()) {
            return q.front();
        }
        return -1;  // Return -1 for an empty queue (assuming all values in the queue are positive)
    }

    // Get the value of the back element
    int back() {
        if (!q.empty()) {
            return q.back();
        }
        return -1;  // Return -1 for an empty queue (assuming all values in the queue are positive)
    }
};

int main() {
    Queue queue;

    // Check if the queue is empty
    if (queue.isEmpty()) {
        cout << "Queue is empty" << endl;
    }

    // Add elements to the queue
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Get the size of the queue
    cout << "Queue size: " << queue.getSize() << endl;

    // Access the front and back elements
    cout << "Front element: " << queue.front() << endl;
    cout << "Back element: " << queue.back() << endl;

    // Remove elements from the queue
    queue.dequeue();

    // Get the new front element
    cout << "New front element: " << queue.front() << endl;

    return 0;
}
