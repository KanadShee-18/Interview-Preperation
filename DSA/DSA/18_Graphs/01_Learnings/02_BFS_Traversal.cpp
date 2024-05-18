/// BFS Traversal in Graph:
// ~~~~~~~~~~~~~~~~~~~~~~~~
// The number of nodes and the adjacency list will be given.

#include <bits/stdc++.h>
using namespace std;

// BFS:
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    int visitedArr[V] = {0};
    visitedArr[0] = 1;
    queue<int> q;
    q.push(0);

    vector<int> bfs;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        bfs.push_back(frontNode);

        for (auto it : adj[frontNode])
        {
            if (visitedArr[it] != 1)
            {
                visitedArr[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main()
{
    int V = 5, E = 4;
    vector<int> adj[V] = {{1, 2, 3}, {}, {4}, {}, {}};
    vector<int> bfs = bfsOfGraph(V, adj);
    cout << "The BFS traversal of the graph is: " << endl
         << endl;
    for (auto it : bfs)
    {
        cout << it << " ";
    }
    return 0;
}