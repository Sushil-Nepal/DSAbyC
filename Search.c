#include<stdio.h>
int sequentialSearch(int arr[],int key,int len){
    for(int i=0;i<len;i++){
        if(arr[i]==key){
            printf("Key is Found at %d\n",i);
            return i;
        }
    }
    printf("key is Not Found :");
    return -1;
}
int binarySearch(int arr[],int key, int len){
    int start=0;
    int end =len-1;
    int mid;
    do{
        mid=(start+end)/2;
        if(arr[mid]==key){
            printf("key is found to at:%d\n",mid);
            return mid;
        }if(arr[mid]<key){
            start=mid+1;
        }if(arr[mid]>key){
            end=mid-1;
        }
    }while(start<=end);
    printf("Key is Not Found\n");
}
int main(){
    int arr[]={5,3,4,7,1};
    int sortArr[]={1,2,3,4,5,6,7};
    int len=sizeof(arr)/sizeof(arr[0]);
    sequentialSearch(arr,4,5);
    len=sizeof(sortArr)/sizeof(sortArr[0]);
    binarySearch(sortArr,6,7);
    return 0;
}
