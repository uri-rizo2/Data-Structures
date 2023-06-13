#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void floydWarshall(vector<vector<int>>& graph, int numVertices) {
    vector<vector<int>> distance(graph);

    // Initialize distance matrix with direct edge weights
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] != 0) {
                distance[i][j] = graph[i][j];
            } else {
                distance[i][j] = numeric_limits<int>::max();
            }
        }
    }

    // Calculate all-pairs shortest paths
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (distance[i][k] != numeric_limits<int>::max() &&
                    distance[k][j] != numeric_limits<int>::max() &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // Print shortest distances
    cout << "Shortest distances between all pairs:" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (distance[i][j] == numeric_limits<int>::max()) {
                cout << "INF ";
            } else {
                cout << distance[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int numVertices = 4;
    vector<vector<int>> graph = {
        {0, 3, numeric_limits<int>::max(), 5},
        {2, 0, numeric_limits<int>::max(), numeric_limits<int>::max()},
        {numeric_limits<int>::max(), 7, 0, 1},
        {6, numeric_limits<int>::max(), numeric_limits<int>::max(), 0},
    };

    floydWarshall(graph, numVertices);

    return 0;
}
