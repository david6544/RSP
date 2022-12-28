#include<bits/stdc++.h>
using namespace std;


// Add an element to the vector in the hashmap to the vertex key
void addUEdge(unordered_map<int,vector<int>> &adj, int src, int dest) {
    adj[src].push_back(dest); 
    adj[dest].push_back(src);
}

void addDEdge(unordered_map<int,vector<int>> &adj, int src, int dest) {
    adj[src].push_back(dest); 
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

void BFS(unordered_map<int,vector<int>> &adj, int src, int Vertices) {

    //Create a boolean vector to check visited status, sized for all vertices
    vector<bool> visited;
    visited.resize(Vertices);

    //Create a queue to hold current list of adjacent vertices to visit
    list<int> queue;

    //Make source node visited and place it on the front of the queue
    visited[src] = true;
    queue.push_back(src);

    //Dont stop until the queue is empty
    while (!queue.empty()) {

        // Dequeue from a vertex from the queue and print it
        src = queue.front();
        cout << src << " ";
        queue.pop_front();

        // Examine each adjacent vertex of src, if it hasnt been visited, mark it and enqueue it
        for (auto adjacent : adj[src]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }

}



int main() { 
 int Vertices = 20; 
 
 // Hashmap for adjacency list with integers as keys and vectors of ints
 unordered_map<int,vector<int>> adj;


 addUEdge(adj, 0, 1); 
 addUEdge(adj, 0, 2); 
 addUEdge(adj, 1, 2); 
 addUEdge(adj, 2, 0); 
 addUEdge(adj, 2, 3); 
 addUEdge(adj, 3, 3); 
 addUEdge(adj, 1, 5); 
 
 printgraph(adj, Vertices); 


/*
    Graph should be as follows for driver code:

    0 - 1 - 5
    | /
    2 - 3


*/



 BFS(adj, 5,Vertices);
 cout << endl;

 return 0; 
}