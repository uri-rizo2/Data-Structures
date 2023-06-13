#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>

using namespace std;

void heapify(vector<int>& nums, int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && nums[left] > nums[largest]) {
        largest = left;
    }

    if (right < size && nums[right] > nums[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(nums[index], nums[largest]);
        heapify(nums, size, largest);
    }
}

void heapSort(vector<int>& nums) {
    int size = nums.size();

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(nums, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

#endif /* HEAP_SORT_H */