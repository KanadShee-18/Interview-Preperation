//// Rotten Oranges:
// ~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>
using namespace std;

// TC -> O(n x m) + O(n x m) ~ O(n x m) and SC -> O(n x m)+ O(n x m) ~ O(n x m)
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // Declare a queue which will store a {row, col} and the time
    queue<pair<pair<int, int>, int>> q;

    // Declare the visited array of n x m size to mark the rotten
    int visArr[n][m];

    int freshCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                visArr[i][j] = 2;
            }
            else
            {
                visArr[i][j] = 0;
            }
            if (grid[i][j] == 1)
            {
                freshCount++;
            }
        }
    }

    int timeTaken = 0;
    int cnt = 0;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        timeTaken = max(timeTaken, time);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && visArr[newRow][newCol] == 0)
            {
                q.push({{newRow, newCol}, time + 1});
                visArr[newRow][newCol] = 2;
                cnt++;
            }
        }
    }
    if (cnt != freshCount)
        return -1;
    return timeTaken;
}

int main()
{
    vector<vector<int>> v{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int rotting = orangesRotting(v);
    cout << "Minimum Number of Minutes Required is:  " << rotting << endl;
    return 0;
}