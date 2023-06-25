#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void floydWarshall(vector<vector<int>>& graph, int numVertices) {
    vector<vector<int>> dist(graph);

    // Applying the Floyd-Warshall algorithm
    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                // If vertex k is on the shortest path from i to j, update the distance
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Printing the shortest distances
    cout << "Shortest distances between all pairs of vertices:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, INF));

    cout << "Enter edge details (source, destination, weight):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src][dest] = weight;
    }

    // Setting diagonal elements to 0
    for (int i = 0; i < numVertices; ++i) {
        graph[i][i] = 0;
    }

    floydWarshall(graph, numVertices);

    return 0;
}
