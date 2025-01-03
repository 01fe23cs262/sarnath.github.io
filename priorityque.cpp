#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>
#include <functional> // for greater<>
using namespace std;

// Dijkstra's Algorithm with priority queue
void dijkstra(map<int, vector<pair<int, double>>>& graph, int source) {
    // Initialize the distance map with infinity for all nodes
    map<int, double> dist;
    for (auto &node : graph) {
        dist[node.first] = numeric_limits<double>::infinity();
    }
    dist[source] = 0.0;

    // Min-heap (priority queue) to store (distance, node)
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
    pq.push({0.0, source});

    while (!pq.empty()) {
        // Extract the node with the smallest distance
        double distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // If the extracted distance is greater than the recorded distance, skip it
        if (distance > dist[node]) continue;

        // Explore neighbors
        for (auto &neighbor : graph[node]) {
            int nextNode = neighbor.first;
            double edgeWeight = neighbor.second;

            // Relax the edge if a shorter path is found
            if (dist[node] + edgeWeight < dist[nextNode]) {
                dist[nextNode] = dist[node] + edgeWeight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    // Print the shortest distances from the source to all other nodes
    for (auto &node : dist) {
        if (node.second == numeric_limits<double>::infinity()) {
            cout << "No path to node " << node.first << endl;
        } else {
            cout << "Shortest distance from " << source << " to " << node.first << " is " << node.second << endl;
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    map<int, vector<pair<int, double>>> graph;

    // Add edges (node, neighbor, weight)
    graph[0].push_back({1, 1.0});
    graph[0].push_back({2, 1.0});
    graph[0].push_back({3, 1.0});
    graph[1].push_back({5, 2.0});
    graph[2].push_back({6, 1.5});
    graph[3].push_back({7, 1.2});
    graph[6].push_back({7, 1.8});

    int source = 0;
    cout << "Running Dijkstra's Algorithm from node " << source << ":\n";
    dijkstra(graph, source);

    return 0;
}
