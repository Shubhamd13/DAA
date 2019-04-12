/*
5. Write a recursive program to find the solution of placing 
n queens on chessboard so that no two queens
attack each other using Backtracking.
*/
#include <stdio.h>
#include<stdlib.h>
int isSafe(int board[][10],int i,int j,int n){
    int row;
    //checking for col whether the queen can be placed or not
    for(row=0;row<i;row++){
        if(board[row][j]==1)
        return 0;
    }
    //checking for left diagonal
    int x=i;
    int y=j;
    while(x>=0&&y>=0){
        if(board[x][y]==1)
        return 0;
        x--;
        y--;
    }
    //checking for right diagonal
     x=i;
     y=j;
    while(x>=0&&y<n){
        if(board[x][y]==1)
        return 0;
        x--;
        y++;
    }
    return 1;
}
int solveNQueens(int board[][10],int i,int n){ //current row and total rows
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1)
                  printf("Q");
                else
                    printf("-");
            }
			printf("\n");
        }
        return 1;
    }
    //recursive case
    //try to place the queen in the current row and rest will be solved by recurssion
    for(int j=0;j<n;j++){
        if(isSafe(board,i,j,n)){
           board[i][j] =1;
           int isItSafe=solveNQueens(board,i+1,n);
           if(isItSafe)
            return 1;
           board[i][j]=0;
        }
    }
    return 0;
}
int main(){
    int n;
    int board[10][10]={0};
    printf("\nEnter the number of queens :");
    scanf("%d",&n);
    if(n>10){
		printf("Enter smaller n.\n");
		exit(0);
	}
    if(!solveNQueens(board,0,n))
		printf("No solution exists for n=%d \n",n);
    return 0;
}
