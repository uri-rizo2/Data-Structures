#ifndef MEDIAN_MAINTENANCE_H
#define MEDIAN_MAINTENANCE_H

#include <queue>
#include <vector>

using namespace std;

void medianMaintenance(vector<int>& nums) {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        if (maxHeap.empty() || num < maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (maxHeap.size() == minHeap.size()) {
            cout << "Median: " << (maxHeap.top() + minHeap.top()) / 2.0 << endl;
        } else {
            cout << "Median: " << maxHeap.top() << endl;
        }
    }
}

#endif /* MEDIAN_MAINTENANCE_H */
