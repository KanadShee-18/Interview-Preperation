//// Graph representation in C++:

#include <bits/stdc++.h>
using namespace std;

// Option 1: Using Adjacency Matrix TC -> O(n) and SC -> O(n * n)
void adjacencyMatrix(int m, int n, vector<vector<int>> &adj)
{
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter the nodes in between which there is edge: ";
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout << endl
         << "The adjacency matrix is looking like: " << endl
         << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - " << endl
         << endl;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << "- - - - - - - - - - - - - - - - - - - - - " << endl;
}

// Method 2: Using List
void adjacencyList(int m, int n)
{
    vector<int> adjList[n + 1]; // create an array of vector of integers
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter the nodes in between which there is edge: ";
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << endl
         << endl
         << "Your adjacency list is looking like: " << endl
         << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - " << endl
         << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "Adjacency list for vertex " << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Declare a adjacency matrix taking the indexes as 1-based.
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    // make the adjacency matrix
    // adjacencyMatrix(m, n, adj);
    adjacencyList(m, n);
    return 0;
}
