# AVL Trees - Study Notes and Documentation

> **WIP: Work In Progress**

---

## Definition
- AVL Tree (Adelson-Velsky and Landis Tree) is a self-balancing binary search tree (BST).
- For every node, the height difference (balance factor) between its left and right subtrees is at most 1.
- Balance Factor = height(left subtree) - height(right subtree)
- Allowed balance factors: -1, 0, 1

## Key Operations
- Insertion: O(log n)
- Deletion: O(log n)
- Search:   O(log n)

## Rebalancing is done using rotations
1. Single Rotations:  
   a) Left Rotation (for Right-Right imbalance)  
   b) Right Rotation (for Left-Left imbalance)  
2. Double Rotations:  
   a) Left-Right Rotation (for Left-Right imbalance)  
   b) Right-Left Rotation (for Right-Left imbalance)

## Use Cases
- Ordered dictionaries/maps  
- Memory indexing  
- Databases and file systems needing balanced BSTs

## Implementation Note
- Each node stores its height to compute balance factors efficiently.
