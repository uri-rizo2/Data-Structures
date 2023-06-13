#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

bool bfs(vector<vector<int>>& residualGraph, vector<int>& parent, int source, int sink) {
    int numVertices = residualGraph.size();
    vector<bool> visited(numVertices, false);

    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[sink];
}

int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    int numVertices = graph.size();
    vector<vector<int>> residualGraph(graph);
    vector<int> parent(numVertices);

    int maxFlow = 0;

    while (bfs(residualGraph, parent, source, sink)) {
        int pathFlow = numeric_limits<int>::max();

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int numVertices = 6;
    int source = 0;
    int sink = 5;
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0},
    };

    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "Maximum Flow (Ford-Fulkerson Algorithm): " << maxFlow << endl;

    return 0;
}
