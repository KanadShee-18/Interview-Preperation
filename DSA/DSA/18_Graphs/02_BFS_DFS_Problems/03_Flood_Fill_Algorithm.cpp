// FLOOD FILL Algorithm:
// ~~~~~~~~~~~~~~~~~~~~

// Link: https://leetcode.com/problems/flood-fill/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(vector<vector<int>> &image, vector<vector<int>> &ans, int row, int col, int delRow[], int delCol[], int initialColor, int newColor)
    {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && ans[newRow][newCol] != newColor && image[newRow][newCol] == initialColor)
            {
                dfs(image, ans, newRow, newCol, delRow, delCol, initialColor, newColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image; // initialize ans with image
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, 1, 0, -1};
        dfs(image, ans, sr, sc, delRow, delCol, initialColor, color);
        return ans; // return the ans array
    }
};

int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;

    cout << "The matrix before the flood fill algorithm is looking like: " << endl
         << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;

    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[0].size(); j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, sr, sc, color);

    cout << endl
         << endl
         << "After flood fill algorithm it's looking like: " << endl
         << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
