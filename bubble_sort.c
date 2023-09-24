#include <stdio.h>
int print(int arr[],int len){
    for(int i=0;i<len;i++){
        printf("%d,",arr[i]);
    }
    printf(" \n");
}
int swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int bubblesort(int arr[],int len){
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[i]){
                swap(arr,i,j);
            }
        }
    }
}
int main(){
    int prices[]={10,12,12,11,19,9,2,31,32,12235,12,234,23,2,3,23,34,1,21,2,1};
    int len=sizeof(prices)/sizeof(prices[0]);
    print(prices,len);
    bubblesort(prices,len);
    printf("working\n");
    print(prices,len);
    return 0;
}