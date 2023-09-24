#include <stdio.h>
int print(int arr[],int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf(" \n");
}
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void insert(int arr[],int len){
    if(len>0){
    if(arr[len-1]>arr[len]){
            swap(arr,len-1,len);
            insert(arr,len-1);
        }
    }
}
void insertionsort(int arr[],int len){
   if(len>1){
    insertionsort(arr,len-1);
    insert(arr,len);
   }
}
int main(){
    int prices[]={10,12,12,11,19,9,2,31,32,12235,12,234,23,2,3,23,34,1,21,2,1};
    int len=sizeof(prices)/sizeof(prices[0]);
    print(prices,len);
    insertionsort(prices,len-1);
    printf("checking recursive sort!!\n");
    print(prices,len);
    return 0;
}