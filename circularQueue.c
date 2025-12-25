#include<stdio.h>
#define MAX 5
typedef struct{
    int front;
    int rear;
    int items[MAX];
    int canDeque;
    int size;
}Queue;
int init(Queue *q){
    q->front=-1;
    q->rear=-1;
    q->canDeque=0;
    q->size=0;
}
int isEmpty(Queue *q){
    return q->size==0;
}
int isFull(Queue *q){
    return q->size==MAX;
}
int dequeue(Queue *q){
    int value;
    if(isEmpty(q)){
        q->canDeque=0;
        printf("Queue is Empty !CAN NOT DEQUEUE\n");
        return -1;
    }
    value=q->items[q->front];
    q->front=(q->front+1)%MAX;
    q->size--;
    return value;
}
void enqueue(Queue *q,int value){
    if(isFull(q)){
        dequeue(q);
    }
    if(isEmpty(q)){
        q->front=0;
    }
    q->rear=(q->front+q->size)%MAX;
    q->size++;
    q->items[q->rear]=value;
}
void dispaly(Queue *q){
    printf("[");
    int i=q->front;
    // printf("%d,",q->items[q->front]);
    // printf("%d,",q->items[q->rear]);
     if(!isEmpty(q)){
        while(i!=q->rear) {
             printf("%d,",q->items[i]);
             i=(i+1)%MAX;;
        } 
        printf("%d",q->items[i]);     
     }
    printf("]\n");
}
int main(){
    Queue q;
    init(&q);
    enqueue(&q,0);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    dispaly(&q);
    printf("%d",dequeue(&q));
    printf("%d",dequeue(&q));
    dispaly(&q);
    enqueue(&q,5);
    enqueue(&q,6);
    dispaly(&q);
    enqueue(&q,7);
    dispaly(&q);
    return 0;
}