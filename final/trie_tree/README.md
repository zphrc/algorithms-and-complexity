# Trie Trees - Study Notes and Documentation

> **WIP: Work In Progress**

---

## Definition
- A **Trie** (also known as a **prefix tree**) is a tree data structure used to store a dynamic set of strings, usually for retrieval operations.
- Often used for **dictionary-like** operations, such as autocomplete or spell checking.

## Properties
1. Each node represents a single **character** or part of a string.
2. The **root** node is typically empty or null.
3. Children of a node represent possible next characters.
4. A node may have a boolean flag to indicate if it marks the **end of a valid word**.
5. Time complexity depends on the **length of the key** (not the number of keys).

## Key Operations
- **Insertion:** O(m), where *m* is the length of the word.
- **Search:**    O(m)
- **Deletion:**  O(m)
- **Prefix Search (Autocomplete):** O(m)

## Advantages
- Fast lookup for keys with common prefixes.
- Efficient memory usage with overlapping prefixes.
- Easily supports prefix matching and lexicographical ordering.

## Drawbacks
- Can consume more space in cases with few overlapping prefixes.
- Requires extra memory for character mapping (usually via arrays or hash maps).

## Common Applications
- Autocomplete systems
- Spell checkers
- IP routing
- T9 predictive text
- Word games (like Boggle or Scrabble)

## Implementation Note
- Each node typically contains:
  - A mapping of characters to child nodes (array or hash map)
  - An optional flag: `is_end_of_word`
- Trie variants:
  - **Compressed Trie (Radix Tree):** Combines chains of single-child nodes.
  - **Suffix Trie:** Stores all possible suffixes of a string.
