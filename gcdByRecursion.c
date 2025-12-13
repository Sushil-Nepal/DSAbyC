#include<stdio.h>
int gcd(int a,int b){
    if(b==0)
        return a;
    gcd(b,a%b);
}
int main(){
    int a,b;
    printf("Enter a Two Interger:");
    scanf("%d %d",&a,&b);
    int result=gcd(a,b);
    printf("GCD of %d & %d is:%d",a,b,result);
    return 0;
}