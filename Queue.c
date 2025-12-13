#include<stdio.h>
#define MAX 5
typedef struct{
    int front;
    int rear;
    int items[MAX];
    int canDeque;
}Queue;
int init(Queue *q){
    q->front=-1;
    q->rear=-1;
    q->canDeque=0;
}
int isEmpty(Queue *q){
    return q->rear==-1;
}
int isFull(Queue *q){
    return q->rear==MAX-1;
}
void enqueue(Queue *q,int value){
    if(isFull(q)){
        printf("Can Not Enqueue!Stack is Full");
        return;
    }
    if(isEmpty(q)){
        q->front=0;
    }
    q->canDeque=1;
    q->items[++q->rear]=value;
}
int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty !CAN NOT DEQUEUE");
        q->canDeque=0;
        return -1;
        
    }
    q->canDeque=1;
    return q->items[q->front++];
}
void dispaly(Queue *q){
    printf("[");
    for(int i=q->front;i<=q->rear;i++){
        printf("%d,",q->items[i]);
    }
    printf("]\n");
}
int main(){
    Queue q;
    init(&q);
    enqueue(&q,2);
    enqueue(&q,3);
    dispaly(&q);
    dequeue(&q);
    dispaly(&q);
    return 0;
}