#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int tsp(vector<vector<int>>& graph, int numVertices, int startVertex) {
    vector<int> vertices;
    for (int i = 0; i < numVertices; i++) {
        if (i != startVertex) {
            vertices.push_back(i);
        }
    }

    int minPathCost = numeric_limits<int>::max();

    do {
        int currentPathCost = 0;
        int k = startVertex;

        for (int i = 0; i < vertices.size(); i++) {
            currentPathCost += graph[k][vertices[i]];
            k = vertices[i];
        }

        currentPathCost += graph[k][startVertex];

        minPathCost = min(minPathCost, currentPathCost);

    } while (next_permutation(vertices.begin(), vertices.end()));

    return minPathCost;
}

int main() {
    int numVertices = 4;
    int startVertex = 0;
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0},
    };

    int minCost = tsp(graph, numVertices, startVertex);
    cout << "Minimum cost for the Traveling Salesman Problem: " << minCost << endl;

    return 0;
}
