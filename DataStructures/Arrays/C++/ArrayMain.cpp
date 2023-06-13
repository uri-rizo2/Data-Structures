#include <iostream>
#include "ArrayFunctions.h"  // Include the header file containing array funcitons 


int main() {
    int target;
   int n;
    cout << "___________________________________________________________________________________________________________________________________________________" << endl << endl;
   
   cout << "_____________________________________________________________Initiate array_______________________________________________________________________________" << endl;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];    // Create an array with the given number of elements
   cout << "Enter elements(use space after element):" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   
   int size = n; // Initialize the variable 'size' with the value of 'n'
   
   // Inserting an element at position
   cout << "___________________________________________________________________________________________________________________________________________________" << endl << endl;
   cout << endl; 
/*
   cout << "_____________________________________________________________Inserting Element_______________________________________________________________________________" << endl;
   cout << "Array before inserting: ";
   printArray(arr, n);
   insertElement(arr, size, 2, 12); // Pass 'size' instead of 'n'
   cout << "Array after insertion: ";
   printArray(arr, size);
   cout << endl; 
    */
   cout << "___________________________________________________________________________________________________________________________________________________" << endl << endl;
  cout << endl; 
/*
   cout << "_____________________________________________________________Sorting in ascending order______________________________________________________________________" << endl;
   
   cout << "Array before Sorting in Ascending order: ";
   printArray(arr, size); // Pass 'size' instead of 'n'
   insertionSortAsc(arr, size); // Pass 'size' instead of 'n'
   cout << "Array after Sorting in Ascending order: ";
   printArray(arr, size); // Pass 'size' instead of 'n'
*/
   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
   cout << endl;
/*
   cout << "_____________________________________________________________Sorting in descending order______________________________________________________________________" << endl;
   
   cout << "Array before Sorting in Descending order: ";
   printArray(arr, size); // Pass 'size' instead of 'n'
   insertionSortDesc(arr, size); // Pass 'size' instead of 'n'
   cout << "Array after Sorting in Descending order: ";
   printArray(arr, size); // Pass 'size' instead of 'n'
*/
   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
  cout << endl;
///*
   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
   cout << endl;
   cout << "_____________________________________________________________Sorting using bubble sort______________________________________________________________________" << endl;

   cout << "Array before buble sorting: ";
   printArray(arr, size); // Pass 'size' instead of 'n'
   bubbleSort(arr, size); // Pass 'size' instead of 'n'
   cout << "Array after bubble sorting: ";
   printArray(arr, size); // Pass 'size' instead of 'n'
//*/
   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
  cout << endl; 
/*
   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
   cout << endl;
   cout << "_____________________________________________________________Sorting using quickSort______________________________________________________________________" << endl;
 
   cout << "Array before quick sorting: ";
   printArray(arr, size); // Pass 'size' instead of 'n'
   quickSort(arr, 0, size-1); // Pass 'size' instead of 'n'
   cout << "Array after quick sorting: ";
   printArray(arr, size); // Pass 'size' instead of 'n'
*/
   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
  cout << endl; 
/*
   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
   cout << endl;
   cout << "_____________________________________________________________Searhing using linearSearch______________________________________________________________________" << endl;
   
    cout << "what number are you looking for? ";
   cin >> target;
    int index = linearSearch(arr, size, target);
    
    if (index != -1) {
        cout << "Target element found at index " << index << endl;
    } else {
        cout << "Target element not found in the array" << endl;
    }
*/
   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
  cout << endl; 
/*
   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
   cout << endl;
   cout << "_____________________________________________________________binarySearch______________________________________________________________________" << endl;
     
     cout << "what number are you looking for? ";
      cin >> target;

     int index = binarySearch(arr, size, target);
    
    if (index != -1) {
        cout << "Target element found at index " << index << endl;
    } else {
        cout << "Target element not found in the array" << endl;
    }
*/
   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
  cout << endl; 
/*
   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
   cout << endl;
   cout << "_____________________________________________________________ Recursive binarySearch______________________________________________________________________" << endl;
 
   cout << "what number are you looking for? ";
   cin >> target;

    int index = binarySearchRecursive(arr, 0, size - 1, target);
    
    if (index != -1) {
        cout << "Target element found at index " << index << endl;
    } else {
        cout << "Target element not found in the array" << endl;
    }
*/
    cout << "___________________________________________________________________________________________________________________________________________________" << endl;
    cout << endl; 
/*
  cout << endl; 
   cout << "_____________________________________________________________Reversre array______________________________________________________________________" << endl;
  
   cout << "Array before reversing: ";
   printArray(arr, size); // Pass 'size' instead of 'n'
   reverseArray(arr, size); // Pass 'size' instead of 'n'
   cout << "Array after reversal: ";
   printArray(arr, size); // Pass 'size' instead of 'n'
*/
  
    cout << "___________________________________________________________________________________________________________________________________________________" << endl;
    cout << endl; 
 /*
  cout << endl; 
   cout << "_____________________________________________________________Shuffle Array______________________________________________________________________" << endl;
   
   cout << "Array before shuffling: ";
   printArray(arr, size); // Pass 'size' instead of 'n'
   shuffleArray(arr, size); // Pass 'size' instead of 'n'
   cout << "Array after shuffling: ";
   printArray(arr, size); // Pass 'size' instead of 'n'

   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
*/
   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
  cout << endl; 
/* 
   cout << "_____________________________________________________________Removing element______________________________________________________________________" << endl;
 
   cout << "Array before removal: ";
   printArray(arr, size); // Pass 'size' instead of 'n'
   removeElement(arr, size, 1); // Pass 'size' instead of 'n'
   cout << "Array after removal: ";
   printArray(arr, size); // Pass 'size' instead of 'n'
*/
   cout << "___________________________________________________________________________________________________________________________________________________" << endl;
   return 0;
}
