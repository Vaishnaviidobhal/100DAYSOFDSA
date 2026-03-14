#include <stdio.h>

int main()
{
    int N;
    scanf("%d",&N);

    int queue[100];
    int stack[100];
    int front=0,rear=-1,top=-1;

    // Input queue elements
    for(int i=0;i<N;i++)
    {
        scanf("%d",&queue[++rear]);
    }

    // Push queue elements into stack
    while(front<=rear)
    {
        stack[++top]=queue[front++];
    }

    // Pop stack elements back to queue
    front=0;
    rear=-1;

    while(top>=0)
    {
        queue[++rear]=stack[top--];
    }

    // Print reversed queue
    for(int i=0;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }

    return 0;
}