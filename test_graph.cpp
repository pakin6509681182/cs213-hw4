#include <iostream>
#include <list>
#include <vector>
#include <queue>

class Graph {
    int V; // Number of vertices in the graph
    std::vector<std::list<int>> adj; // Adjacency list representation of the graph

public:
    Graph(int V); // Constructor

    void addEdge(int v, int w); // Function to add an edge to the graph
    void BFS(int s); // Function to perform Breadth-First Search (BFS) from a starting vertex 's'
    void DFSUtil(int v, std::vector<bool> &visited); // Utility function to perform DFS
    void DFS(int v); // Function to perform Depth-First Search (DFS) from a starting vertex 's'
};

Graph::Graph(int V) {
    this->V = V; // Initialize the number of vertices
    adj.resize(V); // Resize the adjacency list to hold 'V' vertices
}
void Graph::DFSUtil(int v, std::vector<bool> &visited) {
    visited[v] = true;
    std::cout << v << " ";

    for(auto i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
}

void Graph::DFS(int v) {
    std::vector<bool> visited(V, false);
    DFSUtil(v, visited);
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add an edge from vertex 'v' to vertex 'w'
}

void Graph::BFS(int s) {
    std::vector<bool> visited(V, false); // Vector to keep track of visited vertices

    std::queue<int> queue; // Queue to hold the vertices for BFS

    visited[s] = true; // Mark the starting vertex as visited
    queue.push(s); // Add the starting vertex to the queue

    // Continue until the queue is empty
    while(!queue.empty()) {
        s = queue.front(); // Get the next vertex from the front of the queue
        std::cout << s << " "; // Print the vertex
        queue.pop(); // Remove the vertex from the queue

        // For each vertex adjacent to 's'
        for(auto i = adj[s].begin(); i != adj[s].end(); ++i) {
            // If the vertex has not been visited
            if (!visited[*i]) {
                queue.push(*i); // Add the vertex to the queue
                visited[*i] = true; // Mark the vertex as visited
            }
        }
    }
}

int main() {
    Graph g(4); // Create a graph with 4 vertices
    g.addEdge(0, 1); // Add edges to the graph
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2); // Perform BFS starting from vertex 2
    std::cout << std::endl;
    std::cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2); // Perform DFS starting from vertex 2
    return 0;
}