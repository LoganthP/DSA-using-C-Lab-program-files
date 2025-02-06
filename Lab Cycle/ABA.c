#include <stdio.h>
#include <limits.h>
#define MAX 100 
#define INF INT_MAX 


int findMinDistance(int distance[], int visited[], int vertices) 
{
    int min = INF, minIndex;

    for (int v = 0; v < vertices; v++) 
    {
        if (!visited[v] && distance[v] <= min) 
        {
            min = distance[v];
            minIndex = v;
        }
    }
    return minIndex;
}


void dijkstra(int graph[MAX][MAX], int vertices, int source) 
{
    int distance[MAX];  
    int visited[MAX];   
    int parent[MAX];    

    
    for (int i = 0; i < vertices; i++) 
    {
        distance[i] = INF;
        visited[i] = 0;
        parent[i] = -1; 
    }
    distance[source] = 0; 

    
    for (int count = 0; count < vertices - 1; count++) 
    {
        int u = findMinDistance(distance, visited, vertices);

        
        visited[u] = 1;

        
        for (int v = 0; v < vertices; v++) 
        {
            if (!visited[v] && graph[u][v] && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) 
            {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u; 
            }
        }
    }

    
    printf("Vertex\tDistance from Source\tPath\n");
    for (int i = 0; i < vertices; i++) 
    {
        printf("%d\t\t%d\t\t", i, distance[i]);
        int temp = i;
        while (temp != -1) 
        {
            printf("<-%d", temp);
            temp = parent[temp];
        }
        printf("\n");
    }
}


int main() 
{
    int vertices, source;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix of the graph (use 0 for no edge):\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, vertices, source);

    return 0;
}