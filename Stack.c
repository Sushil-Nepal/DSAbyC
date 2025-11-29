#include<stdio.h>
#define MAX 5
int top=-1;
int stack[MAX];
int isFull(){
    return (top==MAX-1);
}
int isEmpty(){
    return (top==-1);
}
int push(int value){
    if(isFull()){
        printf("\nStack is Full\n");
        return 0;
    }
    stack[++top]=value;
    return 1;
}
int pop(){
    return stack[top--];
}
int peak(){
    return stack[top];
}

void display(){
    printf("[");
    for(int i=0;i<=top;i++){
        printf("%d,",stack[i]);
    }
    printf("]\n");
}
int main(){
    int value,choice,input_status;
    while(1){
        printf("\n=====Stack Menu=====");
        printf("\n 1.Push\n 2.pop\n 3.peak \n 4.display \n 5.exit\n");
        printf("====================\n");
        printf("Choose the Option");
        if(choice==5){
            break;
        }
        input_status=scanf("%d",&choice);
        if(input_status==-1){
            printf("\nWrong input type\n");
            choice=0;
        }
        switch(choice){
            case 1:
                printf("\nEnter the value to be Pushed:");
                scanf("%d",&value);
                if(input_status==-1){
                    printf("\nWrong input type\n");
                    break;
                }
                if(!push(value)){
                    printf("\nFailed to Push\n");
                    break;
                }
                printf("\nPush Sucessfully\n");
                break;
            case 2:
                if(!isEmpty()){
                    value=pop();
                    printf("\nPop Value is:%d\n",value);
                    break;
                }
                printf("Can Not Pop ! Stack Is Empty");
                break;
            case 3:
                if(!isEmpty()){
                    value=peak();
                    printf("\npeak Value is:%d\n",value);
                    break;
                }
                printf("Can Not Peak ! Stack Is Empty");
                break;
            case 4:
                printf("Stack is:");
                 display();
                break;
            default:
                printf(".....Invalid Input.....");    
        }
    }
    return 0;
}