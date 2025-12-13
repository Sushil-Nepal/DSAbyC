// Online C compiler to run C program online
#include <stdio.h>
int sumNatural(int n){
    if(n==0){
        return 0;
    }else{
        return n+sumNatural(n-1);
    }
}

int main() {\
    int n;
    printf("Enter the terms:");\
    scanf("%d",&n);\
    int sum=sumNatural(n);
    printf("sum %d:",sum);
    return 0;
}
