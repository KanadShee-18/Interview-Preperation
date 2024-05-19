/// Number of Provinces in a Graph:
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjList[], vector<int> &visArr)
{
    visArr[node] = 1;
    for (auto it : adjList[node])
    {
        if (!visArr[it])
        {
            dfs(it, adjList, visArr);
        }
    }
}

// TC -> O(n) + O(V + 2E) ~ O(n) and SC -> O(n) + O(n) for (visArr + recStackSpace)
int findCircleNum(vector<vector<int>> &isConnected)
{
    // Changing the adjacency matrix to a adj list
    int V = isConnected.size();
    vector<int> adjList[V + 1];

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    // Creating the visited array
    vector<int> visArr(V + 1, 0);
    int count = 0;
    for (int i = 1; i <= V; i++)
    {
        if (visArr[i] == 0)
        {
            count++;
            dfs(i, adjList, visArr);
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> adjMatrix = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int ans = findCircleNum(adjMatrix);
    cout << "The number of provinces in the graph is: " << ans << endl;
    return 0;
}