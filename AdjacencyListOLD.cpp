#include<bits/stdc++.h>

using namespace std;

#define MAXV        100

typedef struct edgenode {
    int y;
    int weight;
    struct edgenode *next;
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    int directed;
} graph;


void initialize_graph (graph *g, bool directed) {
    int i; //counter

    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;

    for (i = 1; i <= MAXV; i++) {
        g->degree[i] = 0;
    }
    
    for (i = 1; i <= MAXV; i++) {
        g->edges[i] = NULL;
    }
}

void insert_edge(graph *g, int x, int y, bool directed) {
    edgenode *p; //temp pointer
    p = new edgenode;

    p->weight = 0;
    p->y = y;
    p-> next = g->edges[x];

    g->edges[x] = p;
    g->degree[x]++;

    if(!directed) {
        insert_edge(g,y,x, true);
    } else {
        g-> nedges++;
    }
}

void read_graph(graph *g, bool directed) {
    int i;  // counter
    int m;  // No of edges
    int x,y; // vertices in edge (x,y)

    initialize_graph(g,directed);


    // Enter Number of vertices and number of edges
    cout << "Enter Number of Vertices and Number of Edges: ";
    scanf("%d %d", &(g->nvertices), &m);

    for (i = 1; i <= m; i++) {
        cout << "Enter start end end point of edge: ";
        scanf("%d %d", &x, &y);
        insert_edge(g,x,y,directed);
    }
}


void print_graph(graph *g) {
    int i;
    edgenode *p;

    for (i = 1; i <= g->nvertices; i++) {
        cout << "Vertex " << i << " connects to: ";
        p = g->edges[i];
        while (p != NULL) {
            printf(" %d,", p->y);
            p = p->next;
        }
        printf("\n");
    }
}



int main(void) {
    graph *Graph1 = new graph;
    bool directed = false;

    initialize_graph(Graph1,directed);
    read_graph(Graph1,directed);
    print_graph(Graph1);
}

