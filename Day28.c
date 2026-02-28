#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create circular linked list
struct Node* createCircularList(int n) {
    if (n <= 0)
        return NULL;

    struct Node *head = NULL, *temp = NULL, *prev = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        temp = createNode(value);

        if (head == NULL) {
            head = temp;
            prev = temp;
        } else {
            prev->next = temp;
            prev = temp;
        }
    }

    // Make it circular
    prev->next = head;

    return head;
}

// Traverse circular linked list
void traverseCircularList(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createCircularList(n);

    traverseCircularList(head);

    return 0;
}