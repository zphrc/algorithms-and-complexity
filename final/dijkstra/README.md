# Dijkstra's Algorithm - Study Notes and Documentation

> **WIP: Work In Progress**

---

## Definition
- Dijkstra’s Algorithm finds the shortest path from a source vertex to all other vertices in a weighted graph with non-negative edge weights.

## Requirements
- Works on graphs with non-negative edge weights.
- Can be applied to both directed and undirected graphs.

## Properties
1. Greedy algorithm: expands the closest unexplored node first.
2. Guarantees the shortest path from the source to each vertex.
3. Time complexity depends on the data structure used:
   - Using a simple array: O(V²)
   - Using a binary heap: O((V + E) log V)

## Key Concepts
- **Distance array:** stores the shortest known distance to each vertex.
- **Priority Queue (Min-Heap):** efficiently fetches the vertex with the smallest tentative distance.
- **Relaxation:** updates the shortest path estimate for neighbors of a vertex.

## Pseudocode (High-Level)
1. Initialize all distances to ∞ except the source (0).
2. Push source into the priority queue.
3. While the queue is not empty:
   - Extract node with minimum distance.
   - For each neighbor:
     - Relax edge if a shorter path is found.
     - Update priority queue accordingly.

## Use Cases
- GPS and navigation systems.
- Network routing protocols.
- Game development (AI pathfinding).

## Comparison with Other Algorithms
- Better than Bellman-Ford for non-negative edge weights (faster).
- Cannot handle negative edge weights (use Bellman-Ford instead).
- A* Algorithm is a heuristic extension of Dijkstra for goal-directed search.

## Implementation Note
- Efficient priority queue (e.g., binary heap or Fibonacci heap) greatly improves performance.
- Graph can be represented using adjacency lists for efficiency in sparse graphs.