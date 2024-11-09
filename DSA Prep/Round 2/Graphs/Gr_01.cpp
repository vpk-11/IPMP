// Graph Representations
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph
{
private:
    int V;
    map<int, vector<int> > adj;

public:
    Graph(int n)
    {
        V = n;
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void printGraph()
    {
        for (int v = 0; v < V; ++v)
        {
            cout << "Adjacency list of vertex " << v << endl;
            cout << v << " => ";
            for (int i = 0; i < adj[v].size(); i++)
                cout << adj[v][i] << " -> ";
            cout << endl;
        }
    }
};

int main()
{
    int V = 5;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.printGraph();
    return 0;
}
