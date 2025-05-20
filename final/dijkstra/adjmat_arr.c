#include <stdio.h>

#define INF 1000000000
#define V_NUM 5  // Number of vertices in the graph

typedef enum { FALSE, TRUE } Boolean;

int minDistance(int[], Boolean[]);
void dijkstra(int[][V_NUM], int);

int main() {
    // Example graph (adjacency matrix)
    int graph[V_NUM][V_NUM] = {
    // 0  1  2  3  4
    { 0,10, 3, 0, 0 }, // Node 0
    { 0, 0, 1, 0, 2 }, // Node 1
    { 0, 4, 0, 0, 8 }, // Node 2
    { 0, 0, 0, 0, 0 }, // Node 3 (no outgoing edges)
    { 0, 0, 0, 7, 0 }  // Node 4
};

    int start = 0;
    dijkstra(graph, start);

    return 0;
}

// Find the unvisited node with the smallest distance
int minDistance(int dist[], Boolean visited[]) {
    int min = INF, min_ndx, x;

    for (x = 0; x < V_NUM; x++)
        if (!visited[x] && dist[x] <= min) {
            min = dist[x];
            min_ndx = x;
        }

    return min_ndx;
}

// Dijkstra's algorithm implementation
void dijkstra(int graph[][V_NUM], int start) {
    int dist[V_NUM];         // Output array: shortest distances
    Boolean visited[V_NUM];     // visited[i] will be true if vertex i is processed

    // Step 1: Initialize distances and visited array
    for (int i = 0; i < V_NUM; i++) {
        dist[i] = INF;
        visited[i] = FALSE;
    }
    dist[start] = 0;

    // Step 2: Find shortest path for all vertices
    int count, currNode, adjNode, x;
    for (int count = 0; count < V_NUM - 1; count++) {
        int currNode = minDistance(dist, visited); // Get the node with the smallest distance
        visited[currNode] = TRUE;

        // Step 3: Relax adjacent nodes
        for (int adjNode = 0; adjNode < V_NUM; adjNode++) {
            if (
                !visited[adjNode] &&
                graph[currNode][adjNode] &&
                dist[currNode] != INF &&
                dist[currNode] + graph[currNode][adjNode] < dist[adjNode]
            ) {
                dist[adjNode] = dist[currNode] + graph[currNode][adjNode];
            }
        }
    }

    // Step 4: Print the result
    printf("Shortest distances from node %d:\n", start);
    for (x = 0; x < V_NUM; x++)
        printf("To node %d: %d\n", x, dist[x]);
}