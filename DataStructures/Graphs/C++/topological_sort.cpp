#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfsTopologicalSort(vector<vector<int>>& graph, int v, vector<bool>& visited, stack<int>& stk) {
    visited[v] = true;

    for (const auto& u : graph[v]) {
        if (!visited[u]) {
            dfsTopologicalSort(graph, u, visited, stk);
        }
    }

    stk.push(v);
}

void topologicalSort(vector<vector<int>>& graph, int numVertices) {
    vector<bool> visited(numVertices, false);
    stack<int> stk;

    for (int v = 0; v < numVertices; v++) {
        if (!visited[v]) {
            dfsTopologicalSort(graph, v, visited, stk);
        }
    }

    cout << "Topological Sorting Order:" << endl;
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    int numVertices = 6;
    vector<vector<int>> graph(numVertices);

    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);

    cout << "Topological Sorting Order:" << endl;
    topologicalSort(graph, numVertices);

    return 0;
}
