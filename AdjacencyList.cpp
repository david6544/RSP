#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjlist[], int E, int V) {
    adjlist[E].push_back(V);
    adjlist[V].push_back(E);
}

void printGraph(vector<int> adjlist[], int V) {
    for (int i = 0; i < V; i++) {
        cout << "\n Adjacency list of vertex " << i << "\n head ";
        for (auto x : adjlist[i]) 
            cout << "-> " << x;
        cout << endl;
    }
}


int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}