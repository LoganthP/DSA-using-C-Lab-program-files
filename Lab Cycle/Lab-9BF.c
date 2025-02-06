#include<stdio.h>
int q[10];
int r=-1, f=0;
int adj[10][10];
int vis[10]={0};
void main()
{
 int n, i, j, s, v, u;
 printf("\n Enter the number of vertex:");
 scanf("%d",&n);
 printf("\n Enter the Adj matrix:\n ");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",&adj[i][j]);
  }
 }
 printf("\n Enter the source vertex:");
 scanf("%d",&s);
 q[++r]=s;
 vis[s]=1;
 printf("%d: ",s);
 while(f<=r)
 {
  u=q[f++];
  for(v=0;v<n;v++)
  {
   if(adj[u][v]==1 && vis[v]==0)
   {
    printf("->%d",v);
    vis[v]=1;
    q[++r]=v;
   }
  }
 }
}