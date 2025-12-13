#include<stdio.h>
#include<conio.h>
int main(){
	int i,space,j,row,n;
	printf("Enter Numer of Row:");
	scanf("%d",&row);
	n=row;
	for(i=0;i<=row;i++){
		for(space=1;space<=n;space++){
			printf(" ");
		}
		for(j=1;j<=i;j++){
			printf(" *");
		}
		printf("\n");
		n--;
	}
}
