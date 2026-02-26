#include <stdio.h>
#include <stdlib.h>

// Define structure of a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert node at end
struct Node* insertEnd(struct Node* head, int value) {
    // Allocate memory dynamically
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If list is empty
    if (head == NULL) {
        head = newNode;
        return head;
    }

    // Traverse to last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link new node
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to traverse forward
void traverseForward(struct Node* head) {
    struct Node* temp = head;
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, value;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    traverseForward(head);

    return 0;
}