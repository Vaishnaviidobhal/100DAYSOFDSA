#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int indegree[MAX];
int queue[MAX];

int main()
{
    int n, m;
    int u, v;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // initialize matrix & indegree
    for(i = 0; i < n; i++)
    {
        indegree[i] = 0;
        for(j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;   // increase indegree
    }

    int front = 0, rear = -1;

    // push nodes with indegree 0
    for(i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
        {
            queue[++rear] = i;
        }
    }

    printf("Topological Order: ");

    int count = 0;

    while(front <= rear)
    {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        // reduce indegree of neighbors
        for(j = 0; j < n; j++)
        {
            if(adj[node][j] == 1)
            {
                indegree[j]--;

                if(indegree[j] == 0)
                {
                    queue[++rear] = j;
                }
            }
        }
    }

    // check for cycle
    if(count != n)
    {
        printf("\nGraph has a cycle! No topo sort possible\n");
    }

    return 0;
}