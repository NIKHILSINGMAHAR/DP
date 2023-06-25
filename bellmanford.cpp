#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge
{
    int src, dest, weight;
};

void BellmanFord(const vector<Edge>& edges, int numVertices, int startVertex) {
    int numEdges = edges.size();

    vector<int> distances(numVertices, numeric_limits<int>::max());
    distances[startVertex] = 0;

    // Relax all edges (V-1) times
    for (int i = 1; i < numVertices; ++i)
     {
        for (const Edge& edge : edges) 
        {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;

            if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) 
            {
                distances[v] = distances[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const Edge& edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;

        if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
            cout << "Graph contains negative-weight cycle!" << endl;
            return;
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from vertex " << startVertex << ":" << endl;
    for (int i = 1; i <= numVertices; ++i) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<Edge> edges(numEdges);

    cout << "Enter edge details (source, destination, weight):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        cout << "Edge " << i + 1 << ": ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    BellmanFord(edges, numVertices, startVertex);

    return 0;
}