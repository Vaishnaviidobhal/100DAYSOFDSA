#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for building tree
struct TreeNode* queue[1000];
int front = 0, rear = 0;

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n && front < rear) {
        struct TreeNode* current = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = newNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

// Check mirror
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL)
        return true;

    if (left == NULL || right == NULL)
        return false;

    if (left->val != right->val)
        return false;

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Check symmetric
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return isMirror(root->left, root->right);
}

// MAIN
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}