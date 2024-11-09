// Is Cycle Present
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class Graph
{
private:
    int V;
    map<int, vector<int>> adj;

public:
    Graph(int n)
    {
        V = n;
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
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
    
    bool isCyclicUtil(int v, vector<bool> visited, vector<bool> &recStack)
    {
        if (visited[v] == false)
        {
            visited[v] = true;
            recStack[v] = true;

            vector<int>::iterator i;
            for (i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
                    return true;
                else if (recStack[*i])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }
    
    bool isCyclic()
    {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && isCyclicUtil(i, visited, recStack))
                return true;
        }
        return false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.isCyclic())
        cout << "Graph contains cycle" << endl;
    else
        cout << "Graph doesn't contain cycle" << endl;
    return 0;
}