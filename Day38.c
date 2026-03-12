
#include <stdio.h>
#include <string.h>

#define MAX 100

int dq[MAX];
int front = -1;
int rear = -1;

int empty(){
    return front == -1;
}

int size(){
    if(empty()) return 0;
    if(rear >= front)
        return rear - front + 1;
    else
        return MAX - front + rear + 1;
}

void push_front(int x){
    if((front == 0 && rear == MAX-1) || (front == rear+1)){
        printf("Deque Overflow\n");
        return;
    }

    if(empty()){
        front = rear = 0;
    }
    else if(front == 0){
        front = MAX - 1;
    }
    else{
        front--;
    }

    dq[front] = x;
}

void push_back(int x){
    if((front == 0 && rear == MAX-1) || (front == rear+1)){
        printf("Deque Overflow\n");
        return;
    }

    if(empty()){
        front = rear = 0;
    }
    else if(rear == MAX-1){
        rear = 0;
    }
    else{
        rear++;
    }

    dq[rear] = x;
}

void pop_front(){
    if(empty()){
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[front]);

    if(front == rear){
        front = rear = -1;
    }
    else if(front == MAX-1){
        front = 0;
    }
    else{
        front++;
    }
}

void pop_back(){
    if(empty()){
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[rear]);

    if(front == rear){
        front = rear = -1;
    }
    else if(rear == 0){
        rear = MAX-1;
    }
    else{
        rear--;
    }
}

void get_front(){
    if(empty()) printf("-1\n");
    else printf("%d\n", dq[front]);
}

void get_back(){
    if(empty()) printf("-1\n");
    else printf("%d\n", dq[rear]);
}

void clear(){
    front = rear = -1;
}

void reverse(){
    if(empty()) return;

    int i = front;
    int j = rear;

    while(i != j && (i + MAX - 1) % MAX != j){
        int temp = dq[i];
        dq[i] = dq[j];
        dq[j] = temp;

        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}

void sort(){
    if(empty()) return;

    int n = size();

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            int a = (front + j) % MAX;
            int b = (front + j + 1) % MAX;

            if(dq[a] > dq[b]){
                int temp = dq[a];
                dq[a] = dq[b];
                dq[b] = temp;
            }
        }
    }
}

int main(){

    int N;
    scanf("%d",&N);

    char op[20];
    int val;

    for(int i=0;i<N;i++){

        scanf("%s",op);

        if(strcmp(op,"push_front")==0){
            scanf("%d",&val);
            push_front(val);
        }

        else if(strcmp(op,"push_back")==0){
            scanf("%d",&val);
            push_back(val);
        }

        else if(strcmp(op,"pop_front")==0){
            pop_front();
        }

        else if(strcmp(op,"pop_back")==0){
            pop_back();
        }

        else if(strcmp(op,"front")==0){
            get_front();
        }

        else if(strcmp(op,"back")==0){
            get_back();
        }

        else if(strcmp(op,"size")==0){
            printf("%d\n", size());
        }

        else if(strcmp(op,"empty")==0){
            printf("%d\n", empty());
        }

        else if(strcmp(op,"clear")==0){
            clear();
        }

        else if(strcmp(op,"reverse")==0){
            reverse();
        }

        else if(strcmp(op,"sort")==0){
            sort();
        }
    }

    return 0;
}
