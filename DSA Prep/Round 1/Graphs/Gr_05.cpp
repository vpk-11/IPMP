// Is there a path between 2 vertices
#include <iostream>
#include <vector>
#include <stack>
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
    bool isReachable(int start, int end)
    {
        vector<bool> visited(V, false);
        stack<int> stk;
        stk.push(start);
        while (!stk.empty())
        {
            int u = stk.top();
            stk.pop();
            if (visited[u] != 1)
            {
                // cout << u << " -> " << flush;
                visited[u] = 1;
                for (int v = adj[u].size() - 1; v >= 0; v--)
                {
                    if (adj[u][v] == end)
                    {
                        return true;
                    }
                    if (visited[adj[u][v]] == 0)
                    {
                        stk.push(adj[u][v]);
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    int V = 5;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int u = 1, v = 3;
    if (g.isReachable(u, v))
        cout << "There is a path from " << u << " to " << v << endl;
    else
        cout << "There is no path from " << u << " to " << v << endl;

    u = 3, v = 1;
    if (g.isReachable(u, v))
        cout << "There is a path from " << u << " to " << v << endl;
    else
        cout << "There is no path from " << u << " to " << v << endl;

    return 0;
}