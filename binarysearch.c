#include <stdio.h>
int binarysearch(int arr[],int ele,int len){
int start=0,end=len-1;
while(start<=end){
int mid=(start+end)/2;
if(arr[mid]==ele){
    return mid;
}
else if(arr[mid]>ele){
end=mid-1;
}
else{
start=mid+1;
}
}
return -1;
}
int main(){
    int prices[]={1,1,2,2,2,3,9,10,11,12,12,12,19,21,23,23,31,32,34,234,12235};
    int size=sizeof(prices)/sizeof(prices[0]);
    int bin=binarysearch(prices,12235,size);
    printf("%d\n%d",bin,size);
    return 0;
}