#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create Node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue Node (for BFS with HD)
struct QNode {
    struct TreeNode* node;
    int hd;
};

// Queue
struct Queue {
    int front, rear, size;
    struct QNode* arr;
};

struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = 0;
    q->size = n;
    q->arr = (struct QNode*)malloc(n * sizeof(struct QNode));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct TreeNode* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Build Tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct TreeNode* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

// Vertical Order Traversal
void verticalOrder(struct TreeNode* root) {
    if (!root) return;

    struct Queue* q = createQueue(1000);
    enqueue(q, root, 0);

    // Map simulation using array
    int map[2000][100];  // store values
    int count[2000] = {0};

    int minHD = 1000, maxHD = 1000;

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);
        struct TreeNode* node = temp.node;
        int hd = temp.hd + 1000; // shift index

        map[hd][count[hd]++] = node->val;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            enqueue(q, node->left, temp.hd - 1);

        if (node->right)
            enqueue(q, node->right, temp.hd + 1);
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
