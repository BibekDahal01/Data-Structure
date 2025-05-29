#include <stdio.h>

void dfs(int graph[100][100], int visited[100], int N, int node) {
    visited[node] = 1;
    printf("%d ", node + 1); 

    for (int i = 0; i < N; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(graph, visited, N, i);
        }
    }
}

int main() {
    int N, source;
    scanf("%d %d", &N, &source);

    int graph[100][100];
    int visited[100] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    dfs(graph, visited, N, source - 1); 
    return 0;
}
