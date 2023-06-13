#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList list;

    // Inserting elements into the linked list
    list.insertAtEnd(5);
    list.insertAtEnd(10);
    list.insertAtEnd(15);
    list.insertAtBeginning(2);

    // Displaying the linked list
    cout << "Linked List: ";
    list.display(); // Output: Linked List: 2 5 10 15

    // Deleting a node from the linked list
    list.deleteNode(10);

    // Displaying the updated linked list
    cout << "Updated Linked List: ";
    list.display(); // Output: Updated Linked List: 2 5 15

    return 0;
}
