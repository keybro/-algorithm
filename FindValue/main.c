#include<stdio.h>
#include<stdlib.h>

void stupid(int a[],int num){
    int flag = 0;
    printf("stupid\n");
    for (int i = 0; i <10; ++i) {
        if (a[i]==num){
            printf("j = %d\n",i+1);
            flag = 1;
        }
    }
    if (flag==0){
        printf("%d\n",0);
    }
}

void binarySearch(int a[],int num){
    printf("binarySearch\n");
    int front = 0,end = 9;
    int mid = (front+end)/2;
    while (front<end){
        if (a[mid]==num){
            break;
        } else if(a[mid]<num){
            front = mid+1;
        } else{
            end = mid-1;
        }
        mid = (front+end)/2;
    }
    if (a[mid]==num){
        printf("j = %d\n",mid+1);
    } else{
        printf("j = %d\n",0);
    }
}
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int num;
    scanf("%d",&num);
    stupid(a,num);
    binarySearch(a,num);
}