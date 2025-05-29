#include <stdio.h>

#define MAX 100

void bfs(int graph[MAX][MAX], int visited[MAX], int N, int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node + 1); 

        for (int i = 0; i < N; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int N, source;
    scanf("%d %d", &N, &source);

    int graph[MAX][MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    bfs(graph, visited, N, source - 1);
    return 0;
}
