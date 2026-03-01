#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to rotate list
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int n = 1;

    // Count nodes
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Make it circular
    temp->next = head;

    k = k % n;
    int steps = n - k;

    temp = head;

    // Traverse to (n-k-1)th node
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // New head
    struct Node* newHead = temp->next;

    // Break circle
    temp->next = NULL;

    return newHead;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k;
    scanf("%d", &k);

    head = rotateRight(head, k);

    // Print rotated list
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}