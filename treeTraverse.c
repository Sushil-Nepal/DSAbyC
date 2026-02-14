#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data ;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int value){
    Node* newNode= (Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
Node* insertNode(Node* root, int value){
    if(root==NULL){
        return createNode(value);
    }else if(root->data>value){
        root->left=insertNode(root->left,value);
    }else if (root->data<value){
        root->right=insertNode(root->right,value);
    }
}
void inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d->",root->data);
        inOrder(root->right);
    }
    
}
void preOrder(Node* root){
    if(root!=NULL){
        printf("%d->",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d->",root->data);
    }
}
int main(){
    Node* root=NULL;
    // printf("Start.....");
    root=insertNode(root,10);
    // printf("Instrt 10");
    root=insertNode(root,5);
    //  printf("Instrt 5");
    root=insertNode(root,15);
    //  printf("Instrt 15");
    preOrder(root);
    
    return 0;
}
