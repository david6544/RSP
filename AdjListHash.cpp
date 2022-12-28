#include<bits/stdc++.h>
using namespace std;


// Add an element to the vector in the hashmap to the vertex key
void addEdge(unordered_map<int,vector<int>> &adj, int src, int dest) {
    adj[src].push_back(dest); 
    adj[dest].push_back(src);
}

// Print each vertex and their edges
void printgraph(unordered_map<int,vector<int>> &adj, int Vertices) {
    
    // Run through each vertex
    for (int i = 0; i < Vertices; i++) {

        // Check if we have hit the end of the vector
        if(adj.find(i) != adj.end()) {
            cout << "\n Adjacency List of vertes " << i << "\n head ";
            
            //Print each value in the vector
            for (auto x : adj[i])
                cout << "-> " << x;
            cout << endl;
        }
    }
}



int main() { 
 int Vertices = 100; 
 
 // Hashmap for adjacency list with integers as keys and vectors of ints
 unordered_map<int,vector<int>> adj;


 addEdge(adj, 0, 1); 
 addEdge(adj, 0, 4); 
 addEdge(adj, 1, 2); 
 addEdge(adj, 1, 7); 
 addEdge(adj, 1, 8); 
 addEdge(adj, 2, 5); 
 addEdge(adj, 2, 4); 
 addEdge(adj, 7, 4); 
 printgraph(adj, Vertices); 
 return 0; 
}