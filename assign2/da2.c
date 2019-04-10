/*
2. Write a program to solve optimal storage on tapes
problem using Greedy approach.
*/
#include<stdio.h>
#include <stdlib.h>
typedef struct Prog{
  int num;
  int size;
}Prog;
int comparator(const void *p, const void *q)
{
    int l = ((Prog *)p)->size;
    int r = ((Prog *)q)->size;
    return (l - r);
}
int main(){
    int n,i,mrt=0;
    Prog arr[20];
    printf("Enter the number of programs:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter length of program P%d :",i+1);
        scanf("%d",&arr[i].size);
        arr[i].num=i+1;
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    qsort((void*)arr, n, sizeof(arr[0]), comparator);
    printf("The best order is: ");
    for(i=0;i<n;i++){
        printf("P%d ",arr[i].num);
    }
    printf("\n");
    for(i=0;i<n;i++){
        mrt+=(n-i)*arr[i].size;
    }
    printf("Mean retrieval time = %f\n",(float)mrt/n);
}

