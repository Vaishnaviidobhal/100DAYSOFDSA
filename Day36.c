#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;
int n;   // size of queue

void enqueue(int value){
    
    if((rear + 1) % n == front){
        return; // queue full
    }

    if(front == -1){
        front = 0;
        rear = 0;
    }
    else{
        rear = (rear + 1) % n;
    }

    queue[rear] = value;
}

void dequeue(){

    if(front == -1){
        return; // queue empty
    }

    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front = (front + 1) % n;
    }
}

void display(){

    if(front == -1){
        return;
    }

    int i = front;

    while(1){
        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % n;
    }
}

int main(){

    int m;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){
        enqueue(arr[i]);
    }

    scanf("%d",&m);

    for(int i=0;i<m;i++){
        dequeue();
    }

    for(int i=0;i<m;i++){
        enqueue(arr[i]);
    }

    display();

    return 0;
}