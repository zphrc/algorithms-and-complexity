# Red-Black Trees - Study Notes and Documentation

> **WIP: Work In Progress**

---

## Definition
- A Red-Black Tree is a self-balancing binary search tree (BST).
- Nodes are colored either **RED** or **BLACK** to enforce balancing rules.

## Properties
1. Every node is either **RED** or **BLACK**.
2. The root is always **BLACK**.
3. Red nodes cannot have red children (no two reds in a row).
4. Every path from a node to its descendant NULL nodes has the same number of **BLACK** nodes.
5. New nodes are inserted **RED** (fix-up is applied afterward).

## Key Operations
- **Insertion:** O(log n)
- **Deletion:**  O(log n)
- **Search:**    O(log n)

## Balancing
- Maintained via a combination of:
  - Rotations (left or right)
  - Recoloring of nodes
- Ensures the tree remains roughly balanced with minimal height.

## Comparison with AVL Trees
- Red-Black Trees are more flexible (allow looser balancing).
- May have slightly worse search performance than AVL.
- Insertion and deletion are often faster in practice.

## Implementation Note
- Each node must track both its color and child pointers.
- Fix-up procedures are required after insertions and deletions to restore properties.
