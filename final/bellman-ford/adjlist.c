#include <stdio.h>

#define INF 1000000000
#define V 6  // Number of vertices: S, A, B, C, D, E
#define E 8  // Number of edges

// Edge structure
struct Edge {
    int src;
    int dest;
    int weight;
};

void bellmanFord(struct Edge edges[], int start) {
    int distance[V];

    // Step 1: Initialize distances
    for (int i = 0; i < V; i++) {
        distance[i] = INF;
    }
    distance[start] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Step 3: (Optional) Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (distance[u] != INF && distance[u] + w < distance[v]) {
            printf("Graph contains a negative-weight cycle\n");
            return;
        }
    }

    // Step 4: Print result
    char labels[] = {'S', 'A', 'B', 'C', 'D', 'E'};
    for (int i = 0; i < V; i++) {
        if (distance[i] == INF)
            printf("Distance from S to %c: INF\n", labels[i]);
        else
            printf("Distance from S to %c: %d\n", labels[i], distance[i]);
    }
}

int main() {
    // Define edges (from, to, weight)
    struct Edge edges[E] = {
        {0, 1, 10},  // S -> A
        {1, 3, 2},   // A -> C
        {3, 2, -2},  // C -> B
        {2, 1, 1},   // B -> A
        {0, 5, 8},   // S -> E
        {5, 4, 1},   // E -> D
        {4, 1, -4},  // D -> A   <-- NEW
        {4, 3, -1}   // D -> C   <-- NEW
    };

    bellmanFord(edges, 0);  // Start from node S (index 0)

    return 0;
}
