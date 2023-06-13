#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> heapArray;
    int heapSize;

    // Helper function to rebalance the heap starting from the given index
    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;   // Index of left child
        int right = 2 * index + 2;  // Index of right child

        // Check if the left child is larger than the current node
        if (left < heapSize && heapArray[left] > heapArray[largest]) {
            largest = left;
        }

        // Check if the right child is larger than the current node
        if (right < heapSize && heapArray[right] > heapArray[largest]) {
            largest = right;
        }

        // If the largest element is not the current node, swap them and continue heapifying
        if (largest != index) {
            swap(heapArray[index], heapArray[largest]);
            heapify(largest);
        }
    }

public:
    Heap() {
        heapSize = 0;
    }

    // Insert a new element into the heap
    void insert(int value) {
        heapArray.push_back(value);  // Add the new element to the end of the array
        heapSize++;                  // Increase the heap size
        int index = heapSize - 1;     // Index of the new element
        int parent = (index - 1) / 2; // Index of the parent of the new element

        // Compare the new element with its parent and swap them if necessary until the heap property is satisfied
        while (index > 0 && heapArray[index] > heapArray[parent]) {
            swap(heapArray[index], heapArray[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Remove and return the top (maximum) element from the heap
    int remove() {
        if (heapSize == 0) {
            throw out_of_range("Heap is empty");
        }

        int top = heapArray[0];                   // Store the top element
        heapArray[0] = heapArray[heapSize - 1];   // Replace the top element with the last element
        heapSize--;                              // Decrease the heap size
        heapArray.pop_back();                     // Remove the last element from the array
        heapify(0);                              // Rebalance the heap starting from the root

        return top;                               // Return the top element
    }

    // Return the top (maximum) element from the heap without removing it
    int top() {
        if (heapSize == 0) {
            throw out_of_range("Heap is empty");
        }

        return heapArray[0];  // Return the top element
    }

    // Return the number of elements in the heap
    int size() {
        return heapSize;
    }

    // Check if the heap is empty
    bool empty() {
        return heapSize == 0;
    }

    // Build a heap from an array of elements
    void buildHeap(vector<int>& array) {
        heapArray = array;         // Copy the array into the heap array
        heapSize = array.size();   // Set the heap size

        // Start heapifying from the last parent down to the root
        for (int i = heapSize / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    // Clear the heap (remove all elements)
    void clear() {
        heapArray.clear();
        heapSize = 0;
    }

    // Print the elements of the heap
    void print() {
        for (int i = 0; i < heapSize; i++) {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap maxHeap;

    // Insert elements into the heap
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(5);

    cout << "Heap size: " << maxHeap.size() << endl;
    cout << "Heap elements: ";
    maxHeap.print();

    // Remove the top element
    cout << "Removing top element: " << maxHeap.remove() << endl;

    // Get the top element
    cout << "Top element: " << maxHeap.top() << endl;

    // Clear the heap
    maxHeap.clear();
    cout << "Heap size after clearing: " << maxHeap.size() << endl;

    return 0;
}
