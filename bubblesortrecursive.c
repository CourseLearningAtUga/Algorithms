#include <stdio.h>
int print(int arr[],int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf(" \n");
}

void bubblesort(int arr[],int len){
   
}
int main(){
    int prices[]={10,12,12,11,19,9,2,31,32,12235,12,234,23,2,3,23,34,1,21,2,1};
    int len=sizeof(prices)/sizeof(prices[0]);
    print(prices,len);
    bubblesort(prices,len-1);
    printf("checking bubble sort!!\n");
    print(prices,len);
    return 0;
}