# Bellman-Ford Algorithm - Study Notes and Documentation

> **WIP: Work In Progress**

---

## Definition
- Bellman-Ford Algorithm finds the shortest path from a source vertex to all other vertices in a weighted graph, even if the graph contains edges with negative weights.

## Requirements
- Works on graphs with negative or positive edge weights.
- Can detect negative weight cycles reachable from the source.
- Applicable to both directed and undirected graphs (though usually directed).

## Properties
1. Dynamic programming approach: iteratively relaxes all edges up to V-1 times.
2. Guarantees shortest paths if no negative weight cycles exist.
3. Can detect the presence of negative weight cycles.
4. Time complexity: O(V × E), where V = number of vertices and E = number of edges.

## Key Concepts
- **Distance array:** stores the shortest known distance to each vertex.
- **Edge Relaxation:** updates the shortest path estimate for edges.
- **Negative Cycle Detection:** if relaxation is still possible after V-1 iterations, a negative cycle exists.

## Pseudocode (High-Level)
1. Initialize all distances to ∞ except the source (0).
2. Repeat V-1 times:
   - For each edge (u, v) with weight w:
     - If dist[u] + w < dist[v], update dist[v].
3. Check for negative weight cycles:
   - For each edge (u, v) with weight w:
     - If dist[u] + w < dist[v], report negative cycle.

## Use Cases
- Graphs with negative edge weights.
- Currency exchange arbitrage detection.
- Routing protocols (e.g., distance-vector routing).
- Situations where negative cycles must be detected.

## Comparison with Other Algorithms
- Can handle negative weights unlike Dijkstra.
- Slower than Dijkstra: O(V × E) vs. O((V + E) log V) with min-heap.
- Does not require a priority queue.
- Cannot be used on graphs with negative cycles (paths undefined).

## Implementation Note
- Usually implemented with adjacency list or edge list for efficient edge iteration.
- Suitable for sparse or dense graphs.
- Straightforward to implement; mainly involves repeated edge relaxation.
