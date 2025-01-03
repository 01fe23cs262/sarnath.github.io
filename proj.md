### Explanation with Respect to a Restaurant Delivery System

### 1) DELIVERY SYSTEM 

This program uses **Dijkstra's algorithm** to find the shortest delivery route from a restaurant to a customer's location.

#### Key Concepts in the Context of Delivery:
1. **Graph Representation**:  
   - Nodes (vertices) represent delivery locations (e.g., restaurant, intersections, customer locations).
   - Edges represent the roads or paths connecting these locations.
   - Edge weights denote the delivery time, distance, or cost associated with a road.

2. **Shortest Path**:
   - The algorithm determines the quickest route from the restaurant (source node) to the customer's address (destination node), considering all possible roads and traffic conditions.

3. **Steps**:
   - **Initialization**: Assign infinite distance to all locations except the starting point (restaurant), which is initialized with zero distance.
   - **Priority Queue**: The algorithm uses a priority queue to explore the location with the currently shortest known distance.
   - **Relaxation**: For each neighboring location, update its distance if the current path is shorter than the previously known path.
   - **Result**: The algorithm ends when the shortest path to the destination is found.

#### Example Application:
- A restaurant (node `0`) is connected to other delivery points via roads with varying weights (delivery times/distances).
- To find the fastest way to deliver an order to the customer's house (node `26`), the system calculates the shortest path and its distance.

---

### Complexity

1. **Time Complexity**:
   - **Priority Queue Operations**: Each edge is relaxed at most once, and the priority queue has at most \( V \) nodes, where \( V \) is the number of nodes.
   - Using a binary heap for the priority queue, the time complexity is \( O((V + E) \log V) \), where \( E \) is the number of edges.

2. **Space Complexity**:
   - **Graph Storage**: \( O(V + E) \) for adjacency lists.
   - **Distance and Predecessor Maps**: \( O(V) \).
   - **Priority Queue**: \( O(V) \).

   Overall, the space complexity is \( O(V + E) \).



### Real-World Implications
- **Efficiency**: The system helps ensure timely deliveries by avoiding congested or slow routes.
- **Scalability**: Works well with many delivery locations and roads, provided the graph is sparse.
- **Customizability**: The weights can adapt to represent real-time traffic or delivery priorities.


**CODE LINK  DIJKSTRA'S :https://github.com/01fe23cs262/sarnath.github.io/blob/d1c2f42aa90c317b588659c0c489f3620d3c382a/dij.cpp**

---



### 2) STORING LOCATIONS ALONG WITH THEIR SHORTEST DISTANCES

### Priority Queue Role:

The priority queue stores restaurants (or locations) along with their current shortest distance from your home.
It always gives priority to the closest restaurant, ensuring that you explore the shortest possible paths first.

### Process:

You start by adding your home to the queue with a distance of 0.
The priority queue will first pop out your home (since it has the shortest distance), then check the neighboring locations (restaurants) that you can directly access from your home.
For each restaurant, if a shorter route is found via your current location, the queue is updated with the new distance for that restaurant.
The queue ensures that each next restaurant processed is the one with the smallest distance from the start, so the algorithm always works on the shortest possible routes.

### Final Outcome:

At the end, you'll have the shortest path to each restaurant, with the queue helping you process them in order of increasing distance.

**Time Complexity:**

Insertion: O(log n) 

Extraction: O(log n) 

Peek: O(1) 

Decrease-Key: O(log n) 

**Space Complexity: O(n)**

**CODE LINK FOR PRIORITY QUE :https://github.com/01fe23cs262/sarnath.github.io/blob/40f71194a508ac78a63d42b454c5188957325b48/priorityque.cpp**

---

### 3) MANAGE INVENTORY

**Update Inventory Item:**

This functionality updates the quantity of a specific item in the inventory.
The inventory is stored in a map<string, int>, where the key is the item name (string), and the value is the quantity of the item (integer).

**Algorithm:**

If the item exists in the inventory, the quantity is incremented by the specified value. If the item does not exist, it is added with the new quantity.
This update operation in a map has a time complexity of O(log n), where n is the number of items in the inventory.

**Check Inventory:**

This functionality displays the current items and their quantities in the inventory.
The map container automatically keeps the items sorted by the item name.

**Algorithm:**

The program iterates over all key-value pairs in the map and prints them out.
The time complexity for displaying all items is O(n), where n is the number of items in the inventory.
