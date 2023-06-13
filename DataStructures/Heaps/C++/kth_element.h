#ifndef KTH_ELEMENT_H
#define KTH_ELEMENT_H

#include <vector>
#include <algorithm>

using namespace std;

int kthLargestElement(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
}

int kthSmallestElement(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[k - 1];
}

#endif /* KTH_ELEMENT_H */
