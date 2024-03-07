#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define N 50
int gr[N][N];
bool vis[N];
void addEdge(int u, int v)
{
 gr[u][v] = 1;
}
void DFS(int x)
{
 vis[x] = true;
 for (int i = 1; i <= N; i++)
 {
 if (gr[x][i] && !vis[i])
 DFS(i);
 }
}
bool isConnected(int n)
{
 memset(vis, false, sizeof vis);
 DFS(1);
 for (int i = 1; i <= n; i++)
 {
 if (!vis[i])
 return false;
 }
 return true;
}
int main()
{
 int n, m, u, v;
 printf("Enter the number of vertices in the
graph: ");
 scanf("%d",&n);
 printf("Enter the number of edges: ");
 scanf("%d",&m);
 printf("Enter the edges (vertex1
vertex2):\n");
 for (int i = 0;i < m; i++)
 {
 scanf("%d %d", &u, &v);
 addEdge(u, v);
 }
 if (isConnected(n))
 printf("The graph is connected.\n");
 else
 printf("The graph is not connected.\n");
 return 0;
}