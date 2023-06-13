#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <limits>

using namespace std;

// Graph class
class Graph {
private:
    bool directed;
    bool weighted;
    unordered_map<int, vector<pair<int, int>>> adjacencyList;  // Adjacency list representation

public:
    // Constructor
    Graph(bool isDirected, bool isWeighted) {
        directed = isDirected;
        weighted = isWeighted;
    }

    // Add a vertex to the graph
    void addVertex(int vertex) {
        adjacencyList[vertex] = vector<pair<int, int>>();
    }

    // Remove a vertex from the graph
    void removeVertex(int vertex) {
        // Remove the vertex from adjacency list
        adjacencyList.erase(vertex);

        // Remove any edges that connect to the vertex
        for (auto& [v, edges] : adjacencyList) {
            auto it = remove_if(edges.begin(), edges.end(), [&](const pair<int, int>& edge) {
                return edge.first == vertex;
            });
            edges.erase(it, edges.end());
        }
    }

    // Add an edge to the graph
    void addEdge(int source, int destination, int weight = 0) {
        // Check if vertices exist
        if (adjacencyList.find(source) == adjacencyList.end() || adjacencyList.find(destination) == adjacencyList.end()) {
            cout << "Vertices do not exist. Cannot add edge." << endl;
            return;
        }

        // Add the edge to adjacency list
        adjacencyList[source].emplace_back(destination, weight);

        // If the graph is undirected, add the reverse edge
        if (!directed) {
            adjacencyList[destination].emplace_back(source, weight);
        }
    }

    // Remove an edge from the graph
    void removeEdge(int source, int destination) {
        // Check if vertices exist
        if (adjacencyList.find(source) == adjacencyList.end() || adjacencyList.find(destination) == adjacencyList.end()) {
            cout << "Vertices do not exist. Cannot remove edge." << endl;
            return;
        }

        // Remove the edge from adjacency list
        auto& edges = adjacencyList[source];
        auto it = remove_if(edges.begin(), edges.end(), [&](const pair<int, int>& edge) {
            return edge.first == destination;
        });
        edges.erase(it, edges.end());

        // If the graph is undirected, remove the reverse edge
        if (!directed) {
            auto& reverseEdges = adjacencyList[destination];
            it = remove_if(reverseEdges.begin(), reverseEdges.end(), [&](const pair<int, int>& edge) {
                return edge.first == source;
            });
            reverseEdges.erase(it, reverseEdges.end());
        }
    }

    // Check if a vertex exists in the graph
    bool hasVertex(int vertex) {
        return adjacencyList.find(vertex) != adjacencyList.end();
    }

    // Check if an edge exists in the graph
    bool hasEdge(int source, int destination) {
        if (!hasVertex(source) || !hasVertex(destination)) {
            return false;
        }

        auto& edges = adjacencyList[source];
        for (const auto& edge : edges) {
            if (edge.first == destination) {
                return true;
            }
        }

        return false;
    }

    // Get the degree of a vertex
    int getDegree(int vertex) {
        if (!hasVertex(vertex)) {
            return -1;
        }

        return adjacencyList[vertex].size();
    }

    // Get the neighbors of a vertex
    vector<int> getNeighbors(int vertex) {
        vector<int> neighbors;

        if (!hasVertex(vertex)) {
            return neighbors;
        }

        for (const auto& edge : adjacencyList[vertex]) {
            neighbors.push_back(edge.first);
        }

        return neighbors;
    }

    // Get the number of vertices in the graph
    int getNumVertices() {
        return adjacencyList.size();
    }

    // Get the number of edges in the graph
    int getNumEdges() {
        int count = 0;

        for (const auto& [vertex, edges] : adjacencyList) {
            count += edges.size();
        }

        if (!directed) {
            count /= 2;  // Divide by 2 for undirected graph
        }

        return count;
    }

    // Clear the graph
    void clear() {
        adjacencyList.clear();
    }

    // Breadth-First Search (BFS)
    vector<int> breadthFirstSearch(int startVertex) {
        vector<int> visited;
        queue<int> q;
        unordered_map<int, bool> isVisited;

        if (!hasVertex(startVertex)) {
            return visited;
        }

        q.push(startVertex);
        isVisited[startVertex] = true;

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            visited.push_back(currentVertex);

            for (const auto& edge : adjacencyList[currentVertex]) {
                int neighbor = edge.first;
                if (!isVisited[neighbor]) {
                    q.push(neighbor);
                    isVisited[neighbor] = true;
                }
            }
        }

        return visited;
    }

    // Depth-First Search (DFS)
    vector<int> depthFirstSearch(int startVertex) {
        vector<int> visited;
        stack<int> s;
        unordered_map<int, bool> isVisited;

        if (!hasVertex(startVertex)) {
            return visited;
        }

        s.push(startVertex);
        isVisited[startVertex] = true;

        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();
            visited.push_back(currentVertex);

            for (const auto& edge : adjacencyList[currentVertex]) {
                int neighbor = edge.first;
                if (!isVisited[neighbor]) {
                    s.push(neighbor);
                    isVisited[neighbor] = true;
                }
            }
        }

        return visited;
    }

    // Dijkstra's Algorithm
    vector<int> dijkstra(int startVertex) {
        vector<int> distances(adjacencyList.size(), numeric_limits<int>::max());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, bool> isVisited;

        if (!hasVertex(startVertex)) {
            return distances;
        }

        pq.push(make_pair(0, startVertex));
        distances[startVertex] = 0;

        while (!pq.empty()) {
            int currentVertex = pq.top().second;
            pq.pop();

            if (isVisited[currentVertex]) {
                continue;
            }

            isVisited[currentVertex] = true;

            for (const auto& edge : adjacencyList[currentVertex]) {
                int neighbor = edge.first;
                int weight = edge.second;

                if (distances[currentVertex] + weight < distances[neighbor]) {
                    distances[neighbor] = distances[currentVertex] + weight;
                    pq.push(make_pair(distances[neighbor], neighbor));
                }
            }
        }

        return distances;
    }
};

// Test the Graph class
int main() {
    // Create a directed, weighted graph
    Graph graph(true, true);

    // Add vertices
    for (int i = 1; i <= 6; i++) {
        graph.addVertex(i);
    }

    // Add edges
    graph.addEdge(1, 2, 7);
    graph.addEdge(1, 3, 9);
    graph.addEdge(1, 6, 14);
    graph.addEdge(2, 3, 10);
    graph.addEdge(2, 4, 15);
    graph.addEdge(3, 4, 11);
    graph.addEdge(3, 6, 2);
    graph.addEdge(4, 5, 6);
    graph.addEdge(5, 6, 9);

    // Test graph properties and functionalities
    cout << "Number of vertices: " << graph.getNumVertices() << endl;
    cout << "Number of edges: " << graph.getNumEdges() << endl;

    cout << "Vertices: ";
    for (int i = 1; i <= 6; i++) {
        if (graph.hasVertex(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "Edges: ";
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (graph.hasEdge(i, j)) {
                cout << "(" << i << ", " << j << ") ";
            }
        }
    }
    cout << endl;

    cout << "Degree of vertex 3: " << graph.getDegree(3) << endl;

    cout << "Neighbors of vertex 4: ";
    vector<int> neighbors = graph.getNeighbors(4);
    for (int neighbor : neighbors) {
        cout << neighbor << " ";
    }
    cout << endl;

    // Test BFS
    cout << "BFS traversal: ";
    vector<int> bfsTraversal = graph.breadthFirstSearch(1);
    for (int vertex : bfsTraversal) {
        cout << vertex << " ";
    }
    cout << endl;

    // Test DFS
    cout << "DFS traversal: ";
    vector<int> dfsTraversal = graph.depthFirstSearch(1);
    for (int vertex : dfsTraversal) {
        cout << vertex << " ";
    }
    cout << endl;

    // Test Dijkstra's Algorithm
    cout << "Shortest distances from vertex 1: ";
    vector<int> shortestDistances = graph.dijkstra(1);
    for (int i = 1; i < shortestDistances.size(); i++) {
        cout << shortestDistances[i] << " ";
    }
    cout << endl;

    return 0;
}
