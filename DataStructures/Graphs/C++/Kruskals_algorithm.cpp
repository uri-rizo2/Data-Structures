#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct Subset {
    int parent;
    int rank;
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalMST(vector<Edge>& edges, int numVertices) {
    vector<Edge> result;
    Subset* subsets = new Subset[numVertices];

    // Initialize subsets
    for (int i = 0; i < numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Sort edges in non-decreasing order by weight
    sort(edges.begin(), edges.end());

    int edgeCount = 0;
    int i = 0;

    while (edgeCount < numVertices - 1 && i < edges.size()) {
        Edge currentEdge = edges[i++];

        int x = find(subsets, currentEdge.source);
        int y = find(subsets, currentEdge.destination);

        if (x != y) {
            result.push_back(currentEdge);
            Union(subsets, x, y);
            edgeCount++;
        }
    }

    cout << "Minimum Spanning Tree (Kruskal's Algorithm):" << endl;
    for (const auto& edge : result) {
        cout << "(" << edge.source << " - " << edge.destination << ") : " << edge.weight << endl;
    }

    delete[] subsets;
}

int main() {
    int numVertices = 5;
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9},
    };

    cout << "Minimum Spanning Tree (Kruskal's Algorithm):" << endl;
    kruskalMST(edges, numVertices);

    return 0;
}
