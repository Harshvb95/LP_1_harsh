#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int source, destination, weight;
};

void bellmanFord(vector<Edge>& edges, int numVertices, int source) {
    vector<int> distance(numVertices, INT_MAX);
    distance[source] = 0;

// The function then runs the main Bellman-Ford algorithm loop, which iterates `numVertices - 1` times. This loop is used to relax edges and update the distances to minimize them.
    for (int i = 0; i < numVertices - 1; i++) {
        for (const Edge& edge : edges) {
            // - Within the loop, it iterates over all edges in the `edges` vector. For each edge, it checks if a shorter path from the source to the destination vertex is found. If so, it updates the distance accordingly.
            if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination]) {
                distance[edge.destination] = distance[edge.source] + edge.weight;
            }
        }
    }
// - After the loop, it checks for negative weight cycles by iterating over the edges again. If any distance can still be minimized, it means a negative weight cycle exists, and it prints a message indicating this.
    for (const Edge& edge : edges) {
        if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination]) {
            cout << "Negative weight cycle detected. The graph contains negative weight cycles." << endl;
            return;
        }
    }

    cout << "Shortest distances from source vertex " << source << " are:" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    int numVertices, numEdges, source;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<Edge> edges(numEdges);

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < numEdges; i++) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(edges, numVertices, source);

    return 0;
}