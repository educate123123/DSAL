/*Represent a graph of city using adjacency matrix /adjacency list. Nodes should represent the various
 landmarks and links should represent the distance between them. Find the shortest path using Dijkstra's
 algorithm from single source to all destination*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define V 5  // Number of landmarks (nodes)

int minDistance(int dist[], bool sptSet[]) 
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) 
    {
        if (!sptSet[v] && dist[v] <= min) 
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int src) 
{
    int dist[V];   // The output array dist[i] will hold the shortest distance from src to i
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) 
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance from source to itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) 
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++) 
        {
            // Update dist[v] if and only if:
            // 1) v is not in the shortest path tree
            // 2) There is an edge from u to v
            // 3) The distance from src to v through u is shorter than the current distance of v
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    cout << "Landmark\tDistance from Source\n";
    for (int i = 0; i < V; i++) 
    {
        cout << (char)(i + 65) << "\t\t" << dist[i] << endl;
    }
}

int main() 
{
    // Graph represented by adjacency matrix (weights represent distances)
    int graph[V][V] = 
    {
        {0, 10, 15, 20, 25},  // A
        {10, 0, 35, 25, 30},  // B
        {15, 35, 0, 30, 40},  // C
        {20, 25, 30, 0, 50},  // D
        {25, 30, 40, 50, 0}   // E
    };

    // Find shortest paths from source (A = 0)
    cout << "Shortest paths from Landmark A (Central Park):\n";
    dijkstra(graph, 0);  // Start from Landmark A

    return 0;
}
