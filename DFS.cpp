#include <bits/stdc++.h>
using namespace std;

// Graph Class
class Graph {
public:
    
    // Map of visisted boolean vertices for DFS
    map<int, bool> visited;

    // hashmap of vertices & edges
    unordered_map<int, vector<int>> adj;

    //total vertices in the map
    int Vertices;

    Graph(int Vertices){this->Vertices = Vertices;};
    void addUEdge(int src, int dest);
    void addDEdge(int src, int dest);
    void DFS(int src);
    void printgraph();
};

// Add an element to the vector in the hashmap to the vertex key
void Graph::addUEdge(int src, int dest) {
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}


// Add directed edge by adding only to the source vector
void Graph::addDEdge(int src, int dest) {
    adj[src].push_back(dest);
}

// Print each vertex and their edges
void Graph::printgraph()
{

    // Run through each vertex
    for (int i = 0; i < Vertices; i++)
    {

        // Check if we have hit the end of the vector
        if (adj.find(i) != adj.end())
        {
            cout << "\n Adjacency List of vertes " << i << "\n head ";

            // Print each value in the vector
            for (auto x : adj[i])
                cout << "-> " << x;
            cout << endl;
        }
    }
}


//Depth first search
void Graph::DFS(int src) {

    // Mark node and print
    visited[src] = true;
    cout << src << " ";

    // Iterator for the vector, runs through all adjacent vertices to this vertex
    vector<int>::iterator i;
    for (i = adj[src].begin(); i != adj[src].end(); ++i)
        
        //if the node hasnt been visited, recur for this node inherintly doing depth first
        if (!visited[*i])
            DFS(*i);
}


int main()
{
    int Vertices = 20;

    Graph g = Graph(Vertices);
    // Hashmap for adjacency list with integers as keys and vectors of ints

    g.addDEdge(1, 2);
    g.addDEdge(2, 4);
    g.addDEdge(1, 3);
    g.addDEdge(2, 5);
    g.addDEdge(2, 3);
    g.addDEdge(3, 3);
    g.printgraph();

    g.DFS(1);

    return 0;
}