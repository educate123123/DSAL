 /*Represent a graph of your college campus using adjacency list /adjacency matrix. Nodes should
 represent the various departments/institutes and links should represent the distance between them. Find
 minimum spanning tree using a) Using Prim’s algorithm.*/

 #include <iostream>
#include <climits>
using namespace std;

#define V 5  // Number of departments (nodes)

// Function to find the minimum key vertex
int minKey(int key[], bool mstSet[]) 
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) 
    {
        if (!mstSet[v] && key[v] < min) 
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's algorithm for MST
void primMST(int graph[V][V]) 
{
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values to pick minimum weight edge
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet as false
    for (int i = 0; i < V; i++) 
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0; // Starting from vertex 0
    parent[0] = -1; // First node has no parent

    // Find the MST
    for (int count = 0; count < V - 1; count++) 
    {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Mark the picked vertex as included in MST
        mstSet[u] = true;

        // Update the key and parent values of adjacent vertices
        for (int v = 0; v < V; v++) 
        {
            // graph[u][v] is non-zero only for adjacent vertices of u
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if the graph[u][v] is smaller than the current key value
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) 
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the constructed MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) 
    {
        cout << (char)(parent[i] + 65) << " - " << (char)(i + 65) << " \t" << graph[i][parent[i]] << endl;
    }
}

int main() 
{
    // Graph represented by adjacency matrix (weights represent distances)
    int graph[V][V] = 
    {
        {0, 10, 20, 30, 40},  // A
        {10, 0, 50, 60, 70},  // B
        {20, 50, 0, 80, 90},  // C
        {30, 60, 80, 0, 100}, // D
        {40, 70, 90, 100, 0}  // E
    };

    // Call the function to find the MST
    primMST(graph);

    return 0;
}
