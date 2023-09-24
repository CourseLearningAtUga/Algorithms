#include <stdio.h>
#include <stdlib.h>
int print(int arr[],int len){
    for(int i=0;i<len;i++){
        printf("%d,",arr[i]);
    }
    printf(" \n");
}
void swap(int *prices,int i,int j){
    int temp=prices[i];
    prices[i]=prices[j];
    prices[j]=temp;
}
int partition(int *prices,int st,int en){
int i=st-1;
int j=st;
int pi=en;
while(j<pi){
    if(prices[j]<prices[pi]){
        swap(prices,++i,j);
    }
    j++;
}
swap(prices,++i,pi);
return i;
}

void quicksort(int *prices,int st,int en){
    if(st<en){
        int mid=partition(prices,st,en);
        quicksort(prices,st,mid-1);
        quicksort(prices,mid+1,en);
    }
}

int main(){
int prices[]={10,12,12,11,19,9,2,31,22,32,12235,12,234,23,2,3,23,34,1,21,2,1};
    int len=sizeof(prices)/sizeof(prices[0]);
    print(prices,len);
    quicksort(prices,0,len-1);
    printf("quick working\n");
    print(prices,len);
    return 0;
}