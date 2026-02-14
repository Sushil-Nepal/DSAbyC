#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct Queue{
    int arr[MAX];
    int front;
    int rear;
}Queue;
void init(Queue *q){
    q->front=-1;
    q->rear=-1;
}

void enqueue(int value,Queue *q) {
    if (q->rear == MAX - 1)
        return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (q->front == -1 || q->front > q->rear)
        return -1;
    return q->arr[q->front++];
}
// Graph using adjacency list
struct Node {
    int data;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}
// BFS function
void BFS(int start,Queue *q) {
    enqueue(start,q);
    visited[start] = 1;
    printf("BFS Traversal: ");
    while (q->front <= q->rear) {
        int current = dequeue(q);
        printf("%d ", current);
        struct Node* temp = adjList[current];
        while (temp != NULL){
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(adjVertex,q);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices = 6;
    Queue q;
    init(&q);
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    BFS(0,&q);
    return 0;
}