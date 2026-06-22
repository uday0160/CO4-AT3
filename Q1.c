#include<stdio.h>

#define INF 999

int min(int a,int b)
{
return a<b?a:b;
}

int main()
{
int n,i,j,k;
int graph[20][20];

printf("Enter number of cities: ");
scanf("%d",&n);

printf("Enter distance matrix:\n");

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&graph[i][j]);

if(graph[i][j]==0 && i!=j)
graph[i][j]=INF;
}
}


/* Floyd Algorithm */

int floyd[20][20];

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
floyd[i][j]=graph[i][j];
}


for(k=0;k<n;k++)
{
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
}
}
}


printf("\nFloyd All Pair Shortest Path:\n");

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
printf("%d ",floyd[i][j]);

printf("\n");
}


/* Simple TSP */

int visited[20]={0};
int path=0;
int current=0;

visited[0]=1;


for(i=0;i<n-1;i++)
{
int next=-1;
int minDist=INF;

for(j=0;j<n;j++)
{
if(!visited[j] && graph[current][j]<minDist)
{
minDist=graph[current][j];
next=j;
}
}

visited[next]=1;
path+=minDist;
current=next;
}

path+=graph[current][0];


printf("\nTSP Minimum Cost = %d",path);


return 0;
}
Input
Enter number of cities: 4

Enter distance matrix:

0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
Output
Floyd All Pair Shortest Path:

0 10 15 20
10 0 25 25
15 25 0 30
20 25 30 0

TSP Minimum Cost = 80
