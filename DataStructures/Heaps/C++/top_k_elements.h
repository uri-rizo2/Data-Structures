#ifndef TOP_K_ELEMENTS_H
#define TOP_K_ELEMENTS_H

#include <vector>
#include <queue>

using namespace std;

inline vector<int> topKElements(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Insert the first k elements into the min heap
    for (int i = 0; i < k; i++) {
        minHeap.push(nums[i]);
    }
    
    // For the remaining elements, if an element is larger than the root of the min heap,
    // replace the root with the current element and adjust the heap
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }
    
    // Store the top k elements from the min heap into a vector
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    // Return the top k elements
    return result;
}

#endif /* TOP_K_ELEMENTS_H */
