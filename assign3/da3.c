/*
3. Write a program to implement Bellman-Ford Algorithm 
using Dynamic Programming and verify the time complexity.
*/
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
int Bellman_Ford(int G[10][10] , int V, int E, int edge[100][2])
{
    int i,u,v,k,distance[20],parent[10],S,flag=1;
    for(i=0;i<V;i++)
        distance[i] = INT_MAX , parent[i] = -1 ;
        printf("Enter source: ");
        scanf("%d",&S);
        distance[S-1]=0 ;
    for(i=0;i<V-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v] , parent[v]=u ;
        }
    }
    for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                flag = 0 ;
        }
        if(flag)
            for(i=0;i<V;i++)
                printf("Vertex %d -> cost = %d parent = %d\n",i+1,distance[i],parent[i]+1);

        return flag;
}
int main()
{
    int V,edge[100][2],G[10][10],i,j,k=0;
    printf("Enter no. of vertices: ");
    scanf("%d",&V);
	if(V>10)
		exit(0);

    printf("Enter graph in matrix form:\n");
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]!=0)
                edge[k][0]=i,edge[k++][1]=j;
        }

    if(Bellman_Ford(G,V,k,edge))
        printf("\nNo negative weight cycle\n");
    else printf("\nNegative weight cycle exists\n");
    return 0;
}
