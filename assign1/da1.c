/*
1. Write a program to find Maximum and Minimum element in
an array using Divide and Conquer strategy
and verify the time complexity.
*/
#include<stdio.h>
typedef struct MinMax{
    int min;
    int max;
}MinMax;
MinMax maxminfunc(int arr[],int start,int end){
    MinMax res;
    if(end==start){
        res.max=arr[start];
        res.min=arr[start];
    }else{
        MinMax left=maxminfunc(arr,start,((start+end)/2));
        MinMax right=maxminfunc(arr,((start+end)/2)+1,end);
        res.max=left.max<right.max ? right.max :left.max;
        res.min=left.min>right.min ? right.min :left.min;
    }
        return res;
}
int main(){
    int n,i,arr[100];
	printf("Enter number of numbers:");
	scanf("%d",&n);
	printf("Enter the numbers:");
	for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
	}
	MinMax res=maxminfunc(arr,0,n-1);
	printf("Maximum is :%d \n",res.max);
	printf("Minimum is :%d \n",res.min);
}

