#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;

    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

void primMST(vector<vector<Edge>>& graph, int numVertices) {
    vector<bool> visited(numVertices, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    int source = 0;

    // Start with the source vertex
    visited[source] = true;

    // Add all edges incident to the source vertex to the priority queue
    for (const auto& edge : graph[source]) {
        pq.push(edge);
    }

    while (!pq.empty()) {
        Edge currentEdge = pq.top();
        pq.pop();

        int u = currentEdge.source;
        int v = currentEdge.destination;
        int weight = currentEdge.weight;

        // If the destination vertex is already visited, skip the edge
        if (visited[v]) {
            continue;
        }

        // Mark the destination vertex as visited
        visited[v] = true;

        // Process the edge (u, v)
        cout << "(" << u << " - " << v << ") : " << weight << endl;

        // Add all edges incident to the destination vertex to the priority queue
        for (const auto& edge : graph[v]) {
            pq.push(edge);
        }
    }
}

int main() {
    int numVertices = 5;
    vector<vector<Edge>> graph(numVertices);

    graph[0].push_back({0, 1, 2});
    graph[0].push_back({0, 3, 6});
    graph[1].push_back({1, 0, 2});
    graph[1].push_back({1, 2, 3});
    graph[1].push_back({1, 3, 8});
    graph[1].push_back({1, 4, 5});
    graph[2].push_back({2, 1, 3});
    graph[2].push_back({2, 4, 7});
    graph[3].push_back({3, 0, 6});
    graph[3].push_back({3, 1, 8});
    graph[3].push_back({3, 4, 9});
    graph[4].push_back({4, 1, 5});
    graph[4].push_back({4, 2, 7});
    graph[4].push_back({4, 3, 9});

    cout << "Minimum Spanning Tree (Prim's Algorithm):" << endl;
    primMST(graph, numVertices);

    return 0;
}
