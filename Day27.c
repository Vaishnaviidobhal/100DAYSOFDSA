#include <stdio.h>
#include <stdlib.h>

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

// Get length of list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection point
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;

    // Move pointer of longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    // Traverse together
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1->data;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1; // No intersection
}

int main() {
    int n, m, x;
    struct Node *head1 = NULL, *head2 = NULL, *temp = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (head1 == NULL) {
            head1 = createNode(x);
            temp = head1;
        } else {
            temp->next = createNode(x);
            temp = temp->next;
        }
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (head2 == NULL) {
            head2 = createNode(x);
            temp = head2;
        } else {
            temp->next = createNode(x);
            temp = temp->next;
        }
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}