// Online C compiler to run C program online
#include <stdio.h>
int fabi(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return fabi(n-1)+fabi(n-2);
    }
}

int main() {
    int n;
    printf("Enter the number:");\
    scanf("%d",&n);\
    int f=fabi(n);
    printf("%d terms of febi is %d:",n,f);
    return 0;
}
