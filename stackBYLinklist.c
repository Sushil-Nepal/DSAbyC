#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Stack {
    Node* top;
} Stack;
int isEmpty(Stack* stack){
    if (stack->top == NULL)
        return 1;
    return 0; 
}
void pop(Stack* stack) {
    if (isEmpty(stack)) {
        return;
    }
    Node* temp = stack->top;
    printf("%d popped from stack\n", temp->data);
    stack->top = stack->top->next;
    free(temp);
}
void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed into stack\n", value);
}
void peak(Stack* stack) {
    if (stack->top == NULL)
        printf("Stack is empty\n");
    printf("Top element is %d\n", stack->top->data);
}
void display(Stack* stack) {
    Node* temp = stack->top;
    printf("Stack elements:");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    Stack stack = {NULL};
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    display(&stack);
    pop(&stack);
    pop(&stack);
    display(&stack);
    peak(&stack);
    display(&stack);
    return 0;
}

