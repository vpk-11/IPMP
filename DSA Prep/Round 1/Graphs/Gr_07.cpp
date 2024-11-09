// Bellman Ford Algorithm
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge
{
    int src, dest, w;
};

struct Graph
{
    int V, E;
    Edge *edge;
    Graph(int v, int e){
        V = v;
        E = e;
        edge = new Edge[E];
    }
};

void BellmanFord(Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int w = graph->edge[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int w = graph->edge[i].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
        cout << src << " to " << i << " -> " << dist[i] << endl;

}

int main()
{
    int V = 5;
    int E = 8;
    Graph *graph = new Graph(V, E);

    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].w = -1;

    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].w = 4;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].w = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].w = 2;

    // add edge 1-4 (or B-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].w = 2;

    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].w = 5;

    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].w = 1;

    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].w = -3;

    BellmanFord(graph, 0);
    return 0;
}
