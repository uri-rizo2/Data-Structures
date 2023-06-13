#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <queue>
#include <vector>

using namespace std;

void priorityQueueExample() {
    priority_queue<int> pq;

    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);

    cout << "Priority Queue: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

#endif /* PRIORITY_QUEUE_H */
