#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

void bellmanFord(vector<Edge>& edges, int numVertices, int source) {
    vector<int> distance(numVertices, numeric_limits<int>::max());
    distance[source] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < numVertices - 1; i++) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (distance[u] != numeric_limits<int>::max() && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;
        if (distance[u] != numeric_limits<int>::max() && distance[u] + w < distance[v]) {
            cout << "Graph contains negative-weight cycle" << endl;
            return;
        }
    }

    // Print shortest distances
    cout << "Shortest distances from vertex " << source << ":" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    int numVertices = 5;
    vector<Edge> edges = {
        {0, 1, 6},
        {0, 2, 4},
        {1, 2, -3},
        {1, 3, 2},
        {2, 3, 3},
        {2, 4, 4},
        {3, 1, 1},
        {3, 4, 2},
        {4, 0, 1},
    };

    int source = 0;
    bellmanFord(edges, numVertices, source);

    return 0;
}
