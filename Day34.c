#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    
    int val = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    
    return val;
}

int evaluatePostfix(char exp[]) {
    int i = 0;
    
    while (exp[i] != '\0') {

        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        else if (exp[i] == ' ')
            ;

        else {
            int val2 = pop();
            int val1 = pop();

            switch(exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }

        i++;
    }

    return pop();
}

int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    printf("Result: %d\n", evaluatePostfix(exp));

    return 0;
}