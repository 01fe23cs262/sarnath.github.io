#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>
#include <unordered_map>

using namespace std;

class DeliverySystem {
    unordered_map<int, vector<pair<int, double>>> graph;

public:
    void addEdge(int u, int v, double weight) {
        graph[u].emplace_back(v, weight);
        graph[v].emplace_back(u, weight); // Assuming undirected graph
    }

    void shortestDistance(int source, int destination) {
        unordered_map<int, double> dist;
        unordered_map<int, int> prev;
        for (const auto& node : graph) {
            dist[node.first] = numeric_limits<double>::infinity();
            prev[node.first] = -1;
        }

        dist[source] = 0.0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
        pq.emplace(0.0, source);

        while (!pq.empty()) {
            auto [currentDist, currentNode] = pq.top();
            pq.pop();

            if (currentDist > dist[currentNode]) continue;

            for (const auto& [neighbor, weight] : graph[currentNode]) {
                double newDist = dist[currentNode] + weight;
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    prev[neighbor] = currentNode;
                    pq.emplace(newDist, neighbor);
                }
            }
        }

        if (dist[destination] == numeric_limits<double>::infinity()) {
            cout << "No path found from " << source << " to " << destination << ".\n";
            return;
        }

        // Print shortest distance
        cout << "Shortest distance from " << source << " to " << destination << " is " << dist[destination] << ".\n";

        // Print path
        vector<int> path;
        for (int at = destination; at != -1; at = prev[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    DeliverySystem delivery;

    vector<tuple<int, int, double>> connections =
        {
            {0, 1, 1.0}, {0, 2, 1.0}, {0, 3, 1.0}, {0, 4, 1.0},
            {1, 5, 2.0}, {2, 6, 1.5}, {3, 7, 2.0}, {4, 8, 1.5},
            {5, 9, 1.5}, {6, 10, 2.0}, {7, 11, 1.5}, {8, 12, 2.0},
            {9, 13, 2.0}, {10, 14, 3.0}, {11, 15, 2.0}, {12, 16, 3.0},
            {13, 17, 3.0}, {14, 18, 5.0}, {15, 19, 3.0}, {17, 20, 5.0},
            {18, 21, 4.0}, {19, 22, 2.0}, {20, 23, 4.0}, {22, 24, 4.0},
            {24, 25, 5.0}, {25, 26, 6.0} // Fixed connection railway network
        };

    // Add connections to the delivery system
    for (auto& conn : connections) {
        int u = get<0>(conn);
        int v = get<1>(conn);
        double weight = get<2>(conn);
        delivery.addEdge(u, v, weight);
    }

    // Example usage of shortestDistance
    int source = 0;       // Starting node
    int destination = 26; // Destination node

    delivery.shortestDistance(source, destination);

    return 0;
}
