#include<stdio.h>
int source,cost[20][20],visited[20],d[20],n,i,j,w,u,min;
void dijkstra(int source , int cost[20][20], int visited[20], int d[20], int n)
{ 
   for(i=1;i<=n;i++)
   {
      visited[i] = 0;	//initialise visited[i] to 0
      d[i] = cost[source][i];	//initialise d[i] to cost[source][i]
   }
   visited[i] = 1;	//change visited[i] to 1
   d[source] = 0;		

   for(j=2;j<=n;j++)
   {
      min = 999;
      for(i=1;i<=n;i++)
      {
	 if(!visited[i])	//if node i is not visited
	 {
	    if(d[i] < min)	//if d[i] is less than min then assign d[i] to min and i to u
	    {
		min = d[i];
		u = i;
	    }
	 }
      }
      visited[u] = 1;	//change visited[u] to 1

     for(w=1;w<=n;w++)
     {
	if(cost[u][w]!=999 && visited[w] == 0)	//if the node i is not visited and cost[u][w] is not equal to 999
	{
	   if(d[w] > cost[u][w] + d[u])		
	   d[w] = cost[u][w] + d[u];
	}
     }
   }
}
 
void main()
{  
   printf("Enter the number of vertices:\n");
   scanf("%d",&n);
   printf("Enter the cost adjacency matrix:\n");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
	 scanf("%d",&cost[i][j]);	//input cost adjacency matrix
      }
   }
   printf("Enter the Source Vertex:\n");
   scanf("%d",&source);
   dijkstra(source, cost, visited, d , n);
   for(i=1;i<=n;i++)
   if(i!=source)
	printf("Shortest path from %d to %d is %d\n",source,i,d[i]);
}

   
