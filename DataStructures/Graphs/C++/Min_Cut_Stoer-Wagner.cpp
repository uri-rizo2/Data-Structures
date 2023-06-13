#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int minimumCut(vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<int> vertices(numVertices);
    vector<bool> isInSet(numVertices, false);

    for (int i = 0; i < numVertices; i++) {
        vertices[i] = i;
    }

    int minCut = numeric_limits<int>::max();

    while (numVertices > 1) {
        vector<int> weights(numVertices, 0);
        int prevVertex = 0;
        int currVertex = 0;

        for (int k = 0; k < numVertices; k++) {
            prevVertex = currVertex;
            currVertex = max_element(weights.begin(), weights.end()) - weights.begin();

            isInSet[currVertex] = true;

            for (int i = 0; i < numVertices; i++) {
                weights[i] += graph[vertices[currVertex]][vertices[i]];
            }

            if (k == numVertices - 2) {
                int s = vertices[prevVertex];
                int t = vertices[currVertex];
                minCut = min(minCut, weights[currVertex]);

                for (int i = 0; i < numVertices; i++) {
                    graph[s][vertices[i]] += graph[t][vertices[i]];
                    graph[vertices[i]][s] += graph[vertices[i]][t];
                }

                vertices.erase(vertices.begin() + currVertex);
                numVertices--;
            }
        }
    }

    return minCut;
}

int main() {
    int numVertices = 4;
    vector<vector<int>> graph = {
        {0, 2, 0, 3},
        {2, 0, 4, 0},
        {0, 4, 0, 1},
        {3, 0, 1, 0},
    };

    int minCut = minimumCut(graph);
    cout << "Minimum Cut (Stoer-Wagner Algorithm): " << minCut << endl;

    return 0;
}
