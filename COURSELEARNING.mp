# **Fundamentals of Algorithms and Problem Solving**

Space and Time Complexities: Study of how the resource usage of an algorithm grows as the input size increases. Common complexity classes include O(1), O(n), O(n^2), O(log n), etc.

Order of an Algorithm: Big-O notation to express the upper bound of an algorithm's runtime.

Efficiency Analysis of Stacks and Queues Revisited: Evaluation of the operations (push, pop, enqueue, dequeue) of stacks and queues, and their time complexities (usually O(1)).

Recursive Definitions: Understanding of how recursive functions are defined and how to approach recursive problem-solving.

Recursive Functions: Functions that call themselves, with base cases to stop recursion.

Towers of Hanoi: A classic recursive problem used to demonstrate recursive solutions. Involves moving disks from one peg to another using auxiliary pegs, with constraints.

Backtracking: A problem-solving method that involves trying solutions and undoing steps (backtracking) if the solution is not viable.
Recursion vs Iteration: Comparison of recursive and iterative approaches to problem-solving, their strengths, and weaknesses.




# **Hashing and Hash Tables**

Direct Address Table: A simple method to map keys directly to indices of a table.

Hash Table: A data structure that stores key-value pairs, using a hash function to compute the index of the storage location.

Hash Functions: Functions used to map keys to table indices. They must minimize collisions and distribute keys uniformly.

Collision Resolution Techniques: Strategies like chaining (linked lists at table indices) and open addressing (probing) to handle cases where multiple keys hash to the same index.



# **Graphs and Trees**

Graphs: Data structures consisting of nodes (vertices) and edges (connections between nodes).

Computer Representation of Graphs: Common representations include adjacency matrices and adjacency lists.

Trees: A special type of graph without cycles, where one node is the root, and all other nodes are its descendants.

Tree Traversals: Methods for visiting all nodes in a tree, such as:
Pre-order traversal

In-order traversal

Post-order traversal

AVL Trees: Self-balancing binary search trees where the difference in height between left and right subtrees is at most 1.

2-3 Trees: A type of balanced search tree that guarantees logarithmic height.

Application of Binary Trees: Binary trees used in various applications like expression trees, decision trees, and heaps.

Tries: A tree-like data structure used for storing strings, often used in applications like autocomplete.

DFS (Depth-First Search): A graph traversal algorithm that explores as far down a branch as possible before backtracking.

BFS (Breadth-First Search): A graph traversal algorithm that explores all neighbors of a node before moving to the next level.




# **Sorting Techniques**

Sorting: The process of arranging data in a particular order (ascending/descending).

Bubble Sort: A simple sorting algorithm where adjacent elements are swapped if they are in the wrong order.

Selection Sort: A sorting algorithm that repeatedly selects the smallest (or largest) element and moves it to the correct position.

Insertion Sort: Builds the sorted array one element at a time by inserting each new element into its correct position.

Merge Sort: A divide-and-conquer algorithm that splits the list into halves, recursively sorts them, and merges them back together.

Quick Sort: A divide-and-conquer algorithm that selects a pivot and partitions the array into elements smaller and larger than the pivot, recursively sorting each partition.

Heap Sort: A comparison-based sorting algorithm using a binary heap to repeatedly extract the maximum or minimum element and build the sorted output.




# **Substring Search Algorithms**

Brute-force Method: A straightforward approach where the pattern is checked at every position in the text.

Boyer-Moore Algorithm: A highly efficient substring search algorithm that skips over sections of the text based on mismatch information.

Knuth-Morris-Pratt Algorithm (KMP): An efficient string matching algorithm that uses partial match information to avoid redundant comparisons.

Rabin-Karp Algorithm: Uses hashing to find a substring, checking potential matches through hash values.





# **Graph Algorithms**

Union-Find Data Structure: A structure that supports efficient union and find operations, often used for connected components in graphs.

Shortest Path Algorithms: Methods like Dijkstra's Algorithm and Bellman-Ford Algorithm to find the shortest path between nodes in a graph.

Minimum Spanning Tree Algorithms: Algorithms like Kruskal's and Prim's that find the minimum spanning tree of a connected graph.




# **Problem Case Studies**
Travelling Salesperson Problem: A classic NP-hard problem that involves finding the shortest possible route that visits each city exactly once.

Knapsack Problem: A problem of selecting items with given weights and values to maximize the value in a knapsack of limited capacity.

Fake Coin Problem: A problem to identify the fake coin (lighter or heavier) using the fewest weighings.

Strassen’s Matrix Multiplication: An algorithm that multiplies two matrices in fewer steps than the standard matrix multiplication method.

Huffman Coding: An optimal prefix code algorithm for data compression, based on the frequency of characters.
