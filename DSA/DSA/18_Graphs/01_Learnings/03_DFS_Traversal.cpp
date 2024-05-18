//// DFS Traversal in GRAPH
// ~~~~~~~~~~~~~~~~~~~~~~~~
// The number of nodes and the adjacency list will be given.

#include <bits/stdc++.h>
using namespace std;

void dfsTraversal(int node, vector<int> adj[], vector<int> &dfs, int visitedArr[])
{
    visitedArr[node] = 1;
    dfs.push_back(node);

    for (auto it : adj[node])
    {
        if (!visitedArr[it])
        {
            dfsTraversal(it, adj, dfs, visitedArr);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    int visArr[V] = {0};
    int startNode = 0;
    vector<int> dfs;
    dfsTraversal(startNode, adj, dfs, visArr);
    return dfs;
}

int main()
{
    int V = 5;
    vector<int> adj[V] = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> dfs = dfsOfGraph(V, adj);
    cout << "The DFS traversal of the graph is: " << endl
         << endl;
    for (auto it : dfs)
    {
        cout << it << " ";
    }
    return 0;
}