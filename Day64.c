#include <stdio.h>

#define MAX 100

void BFS(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int queue[MAX];

    int front = 0, rear = 0;

    // Step 1: push source
    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear) {
        int current = queue[front++];

        // print node
        printf("%d ", current);

        // visit neighbors
        for(int i = 0; i < n; i++) {
            if(adj[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n = 5;

    // Adjacency matrix
    int adj[MAX][MAX] = {
        {0,1,1,0,0},
        {1,0,0,1,1},
        {1,0,0,0,0},
        {0,1,0,0,0},
        {0,1,0,0,0}
    };

    int start = 0;

    printf("BFS Traversal: ");
    BFS(adj, n, start);

    return 0;
}