#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int node, vector<bool>& visited, const vector<vector<int>>& adj) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfsUtil(neighbor, visited, adj);
    }
}

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // For undirected graph
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    dfsUtil(start, visited, adj);
    cout << endl;

    return 0;
}
