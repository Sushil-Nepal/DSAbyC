#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue{
    Node* front;
    Node* rear;
} Queue;
int init(Queue *q){
    q->front=NULL;
    q->rear=NULL;
    return 1;
}
int isEmpty(Queue *q) {
    return q->front==NULL;
}
void enqueue(Queue *q,int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}
void dequeue(Queue *q) {
    struct Node *temp;
    if (isEmpty(q)) {
        printf("Queue is Empty! Cannot Dequeue\n");
        return;
    }

    temp = q->front;
    printf("Dequeued: %d\n", temp->data);

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

void display(Queue *q) {
    struct Node *temp;
    temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    Queue q;
    init(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    display(&q);
    dequeue(&q);
    display(&q);
    return 0;
}