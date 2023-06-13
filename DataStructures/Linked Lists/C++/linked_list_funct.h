#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

// Node class representing a single node in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked list class
class LinkedList {
private:
    Node* head;


bool isEmpty() {
    return head == nullptr;
}

int getSize() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

Node* getHead() {
    return head;
}

Node* getTail() {
    if (head == nullptr) {
        return nullptr;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current;
}

void insertAtPosition(int value, int position) {
    if (position < 0) {
        cout << "Invalid position. Position should be non-negative." << endl;
        return;
    }

    if (position == 0) {
        insertAtBeginning(value);
        return;
    }

    int size = getSize();
    if (position >= size) {
        insertAtEnd(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteAtPosition(int position) {
    if (head == nullptr) {
        cout << "Linked list is empty. No nodes to delete." << endl;
        return;
    }

    int size = getSize();
    if (position < 0 || position >= size) {
        cout << "Invalid position." << endl;
        return;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

int search(int value) {
    int position = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return position;
        }
        position++;
        current = current->next;
    }
    return -1;  // Value not found
}

void reverse() {
    Node* previous = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;
}

int getNthNode(int position) {
    int size = getSize();
    if (position < 0 || position >= size) {
        cout << "Invalid position." << endl;
        return -1;  // Error value
    }

    Node* current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    return current->data;
}

void removeDuplicates() {
    if (head == nullptr || head->next == nullptr) {
        return;  // No duplicates in an empty list or a list with a single node
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next;
        }
    }
}

void merge(LinkedList& otherList) {
    if (otherList.isEmpty()) {
        return;  // Nothing to merge
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = otherList.getHead();
    otherList.head = nullptr;
}

LinkedList split() {
    LinkedList secondHalf;
    if (head == nullptr || head->next == nullptr) {
        return secondHalf;  // No split possible in an empty list or a list with a single node
    }

    Node* slow = head;
    Node* fast = head->next;

    // Move 'fast' pointer two steps ahead and 'slow' pointer one step ahead.
    // When 'fast' reaches the end, 'slow' will be at the middle node.
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    secondHalf.head = slow->next;
    slow->next = nullptr;

    return secondHalf;
}

void rotate(int k) {
    if (head == nullptr || k <= 0) {
        return;  // No rotation possible in an empty list or with a non-positive value of k
    }

    int size = getSize();
    k = k % size;  // Handle cases where k is greater than the size of the list

    if (k == 0) {
        return;  // No rotation needed
    }

    Node* current = head;
    for (int i = 0; i < size - k - 1; i++) {
        current = current->next;
    }

    Node* newHead = current->next;
    current->next = nullptr;

    Node* temp = newHead;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head;
    head = newHead;
}
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

#endif /* LINKEDLIST_H */
