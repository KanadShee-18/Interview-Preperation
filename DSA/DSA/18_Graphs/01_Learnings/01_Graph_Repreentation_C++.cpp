//// Graph representation in C++:

#include <bits/stdc++.h>
using namespace std;

// Option 1: Using Adjacency Matrix TC -> O(n) and SC -> O(n * n)
void adjacencyMatrix(int n, int m)
{
    int adj[n + 1][n + 1];
    memset(adj, 0, sizeof(adj));
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
// Option 1: Using Adjacency Matrix TC -> O(n) and SC -> O(n * n)
// Adjacency Matrix for edge weight:
void adjacencyMatrixOfEdgeWeight(int n, int m)
{
    int adj[n + 1][n + 1];
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        int edgeWeight;
        cout << "Enter the nodes in between which there is edge: ";
        cin >> u >> v;
        cout << "Enter the edge weight b/w these two edges: ";
        cin >> edgeWeight;
        adj[u][v] = edgeWeight;
        adj[v][u] = edgeWeight;
    }

    cout << endl
         << "The adjacency matrix of edge weight is looking like: " << endl
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

// Method 2: Using List (TC -> O(n) SC-> O(E) for directed graph and O(2E) for undirected graph)
void adjacencyList(int m, int n)
{
    vector<int> adjList[n + 1]; // create an array of vector of integers
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter the nodes in between which there is edge: ";
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // this line is for undirected graph
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

// Adjacency List for edge weight:
void adjacencyListOfEdgeWeight(int m, int n)
{
    vector<pair<int, int>> adjList[n + 1]; // create an array of vector of integers
    for (int i = 0; i < m; i++)
    {
        int u, v;
        int edgeWeight;
        cout << "Enter the nodes in between which there is edge: ";
        cin >> u >> v;
        cout << "Enter the edge weight: ";
        cin >> edgeWeight;
        adjList[u].push_back({v, edgeWeight});
        adjList[v].push_back({u, edgeWeight}); // this line is for undirected graph
    }

    cout << endl
         << endl
         << "Your adjacency list of edge weight is looking like: " << endl
         << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - " << endl
         << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "Adjacency list for vertex " << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << "{" << adjList[i][j].first << ", " << adjList[i][j].second << "}";
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

    // Adjacency Matrix:
    // adjacencyMatrix(n, m);
    // Adjacency List:
    // adjacencyList(m, n);

    // Adjacency matrix for edge weight:
    // adjacencyMatrixOfEdgeWeight(n, m);

    // Adjacency List for edge weight:
    adjacencyListOfEdgeWeight(m, n);
    return 0;
}
