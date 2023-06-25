#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

vector<int> dijkstra(vector<vector<pii>>& graph, int start)
{
    int V = graph.size();
    vector<int> dist(V, numeric_limits<int>::max());//infinity= numeric_limits<int>::max()=1e9
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // If the current distance is greater than the stored distance, skip
        if (d > dist[u]) {
            continue;
        }
        //u=edge jaha jaari hai
        //d=weight

        // Process all neighboring nodes of u
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If a shorter path is found, update the distance and enqueue the neighbor
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pii>> graph(V);

    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    vector<int> shortestDistances = dijkstra(graph, start);

    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
