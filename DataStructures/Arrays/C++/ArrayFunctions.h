/*
      Function Definition on an Array data structure, Functions include:

            -
            -
            -
            -
            -
            -
            -
            -
            -
            -
*/ 



#include<iostream>
#include <random>
using namespace std;

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    
    swap(array[i + 1], array[high]);
    return i + 1;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}



void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


int linearSearch(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            cout << "Element found: ";
            return i;  // Found the target element
        }
    }
    return -1;  // Target element not found
}

int binarySearch(int array[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (array[mid] == target) {
            return mid;  // Found the target element
        }
        
        if (array[mid] < target) {
            left = mid + 1;  // Target is in the right half
        } else {
            right = mid - 1;  // Target is in the left half
        }
    }
    
    return -1;  // Target element not found
}

int binarySearchRecursive(int array[], int left, int right, int target) {
    if (left > right) {
        return -1;  // Target element not found
    }
    
    int mid = left + (right - left) / 2;
    
    if (array[mid] == target) {
        return mid;  // Found the target element
    }
    
    if (array[mid] < target) {
        return binarySearchRecursive(array, mid + 1, right, target);  // Search in the right half
    } else {
        return binarySearchRecursive(array, left, mid - 1, target);  // Search in the left half
    }
}

void insertElement(int array[], int& size, int position, int element) {
    // Check if the position is valid
    if (position < 0 || position > size) {
        cout << "Invalid position!" << endl;
        return;
    }
    
    // Shift elements to the right from the given position
    for (int i = size; i > position; i--) {
        array[i] = array[i - 1];
    }
    
    // Insert the element at the given position
    array[position] = element;
    
    // Increment the size of the array
    size++;
}

void removeElement(int array[], int& size, int position) {
    // Check if the position is valid
    if (position < 0 || position >= size) {
        cout << "Invalid position!" << endl;
        return;
    }
    
    // Shift elements to the left from the given position
    for (int i = position; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    
    // Decrement the size of the array
    size--;
    // Announce what element got removed
    cout << "Element in place:  " << position << " was removed." << endl;
}
// Function to perform insertion sort
void insertionSortAsc(int array[], int size) {
   for(int i = 0; i<size; i++) {
      for(int j = i; j > 0; j--)
      {
          // Compare the current element with the previous element
          // If the current element is smaller, swap them
          if (array[j] < array[j-1])
          {
              int temp = array[j];
              array[j] = array[j-1];
              array[j-1] = temp;
          }
          else break; // If the current element is greater or equal, break the inner loop
      }
        cout << "Step " << i  << ": " ;
      // Print the array after each pass of insertion sort
      for (int k = 0; k < size; k++) {
         cout << array[k] << " ";
      }
      cout << endl;
   }
}

void insertionSortDesc(int array[], int size){
   for (int i = 0; i<size; i++){
      for (int j = i; j>0; j--){
         // Compare the current element with the previous element
          // If the current element is smaller, swap them
         if (array[j] > array[j-1]){
            int temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
         }
         else break; // only if current element is greater or equal, break nested loop
      }
      //print the array after each pass 
       cout << "Step " << i  << ": " ;
      for(int k = 0; k<size; k++){
      cout << array[k] << " ";
      }
      cout << endl;
   }
}
void reverseArray(int array[], int size) {
    int start = 0;
    int end = size - 1;
    
    while (start < end) {
        swap(array[start], array[end]);
        start++;
        end--;
    }
}

void shuffleArray(int array[], int size) {
    random_device rd;
    mt19937 generator(rd());
    
    for (int i = size - 1; i > 0; i--) {
        uniform_int_distribution<int> distribution(0, i);
        int j = distribution(generator);
        
        swap(array[i], array[j]);
    }
}


// Function to print the elements of an array
void printArray(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

