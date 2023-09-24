#include <stdio.h>

int print(int arr[],int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf(" \n");
}
void shiftone(int arr[],int i,int j){
    while(j>i){
        arr[j]=arr[j-1];
        j--;
    }
}
void insertionsort(int arr[],int len){
    int j=0;
    for(int i=1;i<len;i++){
        int k=0;
        while(k<=j){
            if(arr[k]>arr[i]){
                break;
            }
            k++;
        }
        int temp=arr[i];
        if(k!=i){
        shiftone(arr,k,i);
        arr[k]=temp;
        j++;
        }
        else{
            j=i;
        }
        
    }
}
int main(){
    int prices[]={10,12,12,11,19,9,2,31,32,12235,12,234,23,2,3,23,34,1,21,2,1};
    int len=sizeof(prices)/sizeof(prices[0]);
    print(prices,len);
    insertionsort(prices,len);
    printf("checking bubble sort!!\n");
    print(prices,len);
    return 0;
}
