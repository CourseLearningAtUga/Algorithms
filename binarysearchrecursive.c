#include <stdio.h>
int binarysearch(int arr[],int ele,int start,int end){
    int mid=(start+end)/2;
    if(start<=end){
    if(arr[mid]==ele){
        return mid;
    }
    else if(arr[mid]>ele){
        return binarysearch(arr,ele,start,mid-1);
    }
    else{
        return binarysearch(arr,ele,mid+1,end);
    }
    }
    
}
int main(){
    int prices[]={1,1,2,2,2,3,9,10,11,12,12,12,19,21,23,23,31,32,34,234,12235};
    int size=sizeof(prices)/sizeof(prices[0]);
    int bin=binarysearch(prices,10,0,size-1);
    printf("%d\n%d",bin,size);
    return 0;
}