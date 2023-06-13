#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfsVisit(vector<vector<int>>& graph, int v, vector<bool>& visited, stack<int>& stk) {
    visited[v] = true;

    for (const auto& u : graph[v]) {
        if (!visited[u]) {
            dfsVisit(graph, u, visited, stk);
        }
    }

    stk.push(v);
}

void dfs(vector<vector<int>>& graph, int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (const auto& u : graph[v]) {
        if (!visited[u]) {
            dfs(graph, u, visited);
        }
    }
}

void kosarajuSCC(vector<vector<int>>& graph, int numVertices) {
    vector<bool> visited(numVertices, false);
    stack<int> stk;

    // Perform DFS and fill the stack with vertices in order of their finishing times
    for (int v = 0; v < numVertices; v++) {
        if (!visited[v]) {
            dfsVisit(graph, v, visited, stk);
        }
    }

    // Transpose the graph
    vector<vector<int>> transpose(numVertices);
    for (int v = 0; v < numVertices; v++) {
        for (const auto& u : graph[v]) {
            transpose[u].push_back(v);
        }
    }

    // Reset visited array
    fill(visited.begin(), visited.end(), false);

    // Process the vertices in order of their finishing times
    while (!stk.empty()) {
        int v = stk.top();
        stk.pop();

        if (!visited[v]) {
            dfs(transpose, v, visited);
            cout << endl;
        }
    }
}

int main() {
    int numVertices = 8;
    vector<vector<int>> graph(numVertices);

    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[1].push_back(4);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(5);
    graph[4].push_back(5);
    graph[4].push_back(6);
    graph[5].push_back(0);
    graph[6].push_back(7);
    graph[7].push_back(6);

    cout << "Strongly Connected Components (Kosaraju's Algorithm):" << endl;
    kosarajuSCC(graph, numVertices);

    return 0;
}
