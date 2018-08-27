# Algorithms and Data Structures

My implementation and some notes to review when needed. More description is in the file.

## Algorithm
- [Knuth–Morris–Pratt algorithm:](../master/Algorithms/KMP.cpp) In computer science, the Knuth–Morris–Pratt string-searching algorithm (or KMP algorithm) searches for occurrences of a "word" W within a main "text string" S by employing the observation that when a mismatch occurs, the word itself embodies sufficient information to determine where the next match could begin, thus bypassing re-examination of previously matched characters.

- [Modular Exponentiation:](../master/Algorithms/ModularExponentiation.cpp) Given three numbers x, y and p, compute (x^y) % p. Here we also take care of large numbers.

## Data structures
- [Adjacency list:](../master/DataStructures/AdjacencyList.cpp) In graph theory and computer science, an adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a vertex in the graph. It is easy to find all the neighbor of a node.

- [Edge list:](../master/DataStructures/EdgeList.cpp) Edge list describes the set of neighbors of a vertex in the graph. Each element describe an edge with two vertices.

- [Hash map:](../master/DataStructures/UsingHash.cpp) In computing, a hash table (hash map) is a data structure that implements an associative array abstract data type, a structure that can map keys to values. This is an example on how to use Hash map to solve problem 898C Codeforces. 

- [Heap:](../master/DataStructures/Heap.cpp) A heap is a specialized tree-based data structure that satisfies the heap property: if P is a parent node of C, then the key (the value) of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the key of C.

- [Binary Search Tree:](../master/DataStructures/BinarySearchTree.cpp) In computer science, binary search trees (BST), sometimes called ordered or sorted binary trees, are a particular type of container: data structures that store "items" (such as numbers, names etc..) in memory. When you look for a value, it takes only O(n) complexity.

## Graph
- [Disjoint Set Union:](../master/Graph/DisjointSetUnion.cpp) In this example we will input in edges of a tree, then we will build a tree based on this input using disjoint union set technique: Finding the parent of a node, then decide where that node locates in this tree.

- [Strong connected component:](../master/Graph/Strong_Connected_Component.cpp) ...

- [Hamilton cycle:](../master/Graph/Hamilton_Cycle.cpp) ...

- [Bellman - Ford:](../master/Graph/Ford-Bellman.cpp) The Bellman–Ford algorithm is an algorithm that computes shortest paths from a single source vertex to all of the other vertices in a weighted digraph.
