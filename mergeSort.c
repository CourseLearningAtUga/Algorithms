#include <stdio.h>
#include <stdlib.h>
int *temp;
int print(int arr[],int len){
    for(int i=0;i<len;i++){
        printf("%d,",arr[i]);
    }
    printf(" \n");
}
void merge(int *prices,int st1,int en1,int st2,int en2){
    int pt=0;
    int st=st1;
    int en=en2;
    while(st1<=en1 || st2<=en2){
        if(st1<=en1 && st2<=en2){
            if(prices[st1]<prices[st2]){
                temp[pt]=prices[st1];
                st1++;
            }
            else{
                temp[pt]=prices[st2];
                st2++;
            }
        }
        else if(st1<=en1){
            temp[pt]=prices[st1];
            st1++;
        }
        else{
            temp[pt]=prices[st2];
            st2++;
        }
        pt++;
    }
    pt=0;
    while(st<=en){
        prices[st]=temp[pt];
        st++;
        pt++;
    }
}
void mergesort(int *prices,int start,int end){
    if(start<end){
    int  mid=(start+end)/2;
    mergesort(prices,start,mid);
    mergesort(prices,mid+1,end);
    merge(prices,start,mid,mid+1,end);
    }
}
int main(){
    int prices[]={10,12,12,11,19,9,2,31,22,32,12235,12,234,23,2,3,23,34,1,21,2,1};
    int len=sizeof(prices)/sizeof(prices[0]);
    temp=(int*)malloc(sizeof(int)*len);
    print(prices,len);
    mergesort(prices,0,len-1);
    printf("merge working\n");
    print(prices,len);
    return 0;
}