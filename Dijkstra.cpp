#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int minDistance(const vector<int>& dist, const vector<bool>& visited, int V) {
    int min = INF, min_index = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(const vector<vector<int>>& graph, int V, int src) {
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex\tDistance from Source " << src << "\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << i << "\t\t" << "INF\n";
        else
            cout << i << "\t\t" << dist[i] << "\n";
    }
}

int main() {
    int V, src;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    cout << "Enter source vertex (0 to " << V - 1 << "): ";
    cin >> src;

    dijkstra(graph, V, src);

    return 0;
}
