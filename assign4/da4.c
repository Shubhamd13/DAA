#include<stdio.h>
#include<limits.h>
int n=4;
int dist[10][10] = {0};
int VISITED_ALL;

int dp[16][4];


int  tsp(int mask,int pos){
	
	if(mask==VISITED_ALL){
		return dist[pos][0];
	}
	if(dp[mask][pos]!=-1){
	   return dp[mask][pos];
	}

	//Now from current node, we will try to go to every other node and take the min ans
	int ans = INT_MAX;

	//Visit all the unvisited cities and take the best route
	for(int city=0;city<n;city++){

		if((mask&(1<<city))==0){

			int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
			ans = ans >newAns ? newAns : ans;
		}

	}
	
	return dp[mask][pos] = ans;
} 

int main(){
    /* init the dp array */
	int i,j;
    for( i=0;i<(1<<n);i++){
        for(j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
	printf("Enter the graph in matrix form(4x4) :\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&dist[i][j]);
	VISITED_ALL = (1<<n) -1;
	printf("Travelling Salesman Distance is %d \n",tsp(1,0));

return 0;
}

