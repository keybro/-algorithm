#include <stdio.h>
#include <stdlib.h>
void mergeSort(int arr[],int start,int end);
int merge(int arr[],int start,int mid,int end);
void printAns(int arr[],int length);
int main(){
    int arr[] = {3,5,9,1,88,32,45,78,2,8};
    mergeSort(arr,0,9);
    printAns(arr,10);
}
void mergeSort(int arr[],int start,int end){
    if (start>=end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}
int merge(int arr[],int start,int mid,int end){
    int ans[10];
    int k = 0;
    int i = start;
    int j =mid+1;
    while (i<=mid&&j<=end){
        if (arr[i]<arr[j]){
            ans[k++] = arr[i++];
        }
        else{
            ans[k++] = arr[j++];
        }
    }
    if (i==mid+1){
        while (j<=end){
            ans[k++] = arr[j++];
        }
    }
    if (j==end+1){
        while (i<=mid){
            ans[k++] = arr[i++];
        }
    }
    for(j = 0, i = start;j<k;j++,i++){
        arr[i]  = ans[j];
    }
}
void printAns(int arr[],int length){
    for (int i = 0; i < length; ++i) {
        printf("%d ",arr[i]);
    }
}
