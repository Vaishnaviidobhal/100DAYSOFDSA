#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        // Create new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;   // First node
            temp = newNode;
        } else {
            temp->next = newNode; // Link previous node
            temp = newNode;       // Move temp
        }
    }

    // Traversing
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}