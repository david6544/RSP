#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    int V;
    vector<list<int>> adjlist;
    Graph(int V);
    
    void addEdge(int v, int w);
    
    void BFS(int root);

};

Graph::Graph(int V) {
    this->V = V;
    adjlist.resize(V);
}


void Graph::addEdge(int V, int E) {
    adjlist[V].push_back(E);
}

void Graph::BFS(int root) {
    vector<bool> visited;
    visited.resize(V,false);

    list<int> queue;

    visited[root] = true;
    queue.push_back(root);

    while(!queue.empty()) {
        root = queue.front();
        cout << root << " ";
        queue.pop_front();

        for (auto adjacent: adjlist[root]) {
            if(!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
    cout << endl;
}



int main() {
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 3);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 0) \n";
    g.BFS(0);
 
    return 0;
}