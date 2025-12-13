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
void enqueue(Queue *q,int value){
   
    if(isEmpty(q)){
        q->front=0;
    }
    q->rear=(q->front+q->size)%MAX;
    q->size++;
    q->items[q->rear]=value;
}
int dequeue(Queue *q){
    int value;
    if(isEmpty(q)){
        printf("Queue is Empty !CAN NOT DEQUEUE\n");
        return -1;
    }
    q->canDeque=1;
    value=q->items[q->front];
    q->front=(q->front+1)%MAX;
    return value;
}
void dispaly(Queue *q){
    printf("[");
    int i=q->front;
        while(!isEmpty(q)&&(i-1)!=q->rear){
            printf("%d,",q->items[i]);
            i++;
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
    enqueue(&q,5);
    dispaly(&q);
    printf("%d",dequeue(&q));
    
    dispaly(&q);
    return 0;
}