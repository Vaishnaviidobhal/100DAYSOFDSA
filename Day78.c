#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1005

// Structure for adjacency list
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

// Create new node
Node* newNode(int v, int w) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->v = v;
    temp->w = w;
    temp->next = NULL;
    return temp;
}

// Add edge (undirected)
void addEdge(int u, int v, int w) {
    Node* temp = newNode(v, w);
    temp->next = adj[u];
    adj[u] = temp;

    temp = newNode(u, w);
    temp->next = adj[v];
    adj[v] = temp;
}

// Min heap structure
typedef struct {
    int node, weight;
} HeapNode;

HeapNode heap[MAX * MAX];
int size = 0;

// Swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Push to heap
void push(int node, int weight) {
    heap[++size].node = node;
    heap[size].weight = weight;

    int i = size;
    while (i > 1 && heap[i].weight < heap[i / 2].weight) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

// Pop from heap
HeapNode pop() {
    HeapNode root = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while (2 * i <= size) {
        int smallest = i;
        if (heap[2 * i].weight < heap[smallest].weight)
            smallest = 2 * i;
        if (2 * i + 1 <= size && heap[2 * i + 1].weight < heap[smallest].weight)
            smallest = 2 * i + 1;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }

    return root;
}

// Prim's Algorithm
int prim(int n) {
    int visited[MAX] = {0};
    int total = 0;

    push(1, 0); // start from node 1

    while (size > 0) {
        HeapNode top = pop();
        int u = top.node;
        int w = top.weight;

        if (visited[u]) continue;

        visited[u] = 1;
        total += w;

        Node* temp = adj[u];
        while (temp) {
            if (!visited[temp->v]) {
                push(temp->v, temp->w);
            }
            temp = temp->next;
        }
    }

    return total;
}

// Main
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    printf("%d\n", prim(n));

    return 0;
}