#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Hash {
    Node* arr[10];
} Hash;
int calculateIndex(int key) {
    return key % 10;//max riminder are 0-9
}

Node* createNode(int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = value;
    n->next = NULL;
    return n;
}

void init(Hash* h) {
    for (int i = 0; i < 10; i++) {
        h->arr[i] = NULL;
    }
}

void Insert(int value, Hash* h) {
    int index = calculateIndex(value);
    Node* newNode = createNode(value);

    if (h->arr[index] == NULL) {
        h->arr[index] = newNode;
    } else {
        Node* temp = h->arr[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int find(int key, Hash* h) {
    int index = calculateIndex(key);
    Node* temp = h->arr[index];
    int j = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d found at index [%d][%d]\n", key,index, j);
            return 1;
        }
        temp = temp->next;
        j++;
    }

    printf("Value not found\n");
    return 0;
}

void display(Hash* h) {
    for (int i = 0; i < 10; i++) {
        Node* temp = h->arr[i];
        printf("Index %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Hash h;
    init(&h);
    Insert(22, &h);
    Insert(23, &h);
    Insert(24, &h);
    Insert(25, &h);
    Insert(32, &h);  // collision with 22
    display(&h);
    find(23, &h);
    find(99, &h);
    return 0;
}
