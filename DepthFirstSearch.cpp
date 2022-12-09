#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    map<int, bool> visited;
    map<int, list<int>> adjlist;
    
    void addEdge(int v, int w);
    
    void DFS(int root);

};

void Graph::addEdge(int V, int E) {
    adjlist[V].push_back(E);
}

void Graph::DFS(int root) {
    visited[root] = true;
    cout << root << " ";

    list<int>::iterator i;
    for (i = adjlist[root].begin(); i != adjlist[root].end(); i++) {
        if (!visited[*i]) {
            DFS(*i);
        }
    }
}




int main() {
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 3);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 0) \n";
    g.DFS(2);
 
    return 0;
}