#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<bool>& visited, stack<int>& stk, const vector<vector<int>>& adj, int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(visited, stk, adj, neighbor);
    }
    stk.push(node);  
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v) - directed edge u->v:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> visited(V, false);
    stack<int> stk;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(visited, stk, adj, i);
    }

    cout << "Topological Sort: ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    return 0;
}
