//// Check if binary tree is height-balanced or not:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Link: https://leetcode.com/problems/balanced-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int dfsHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode *root)
    {
        return dfsHeight(root) != -1;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create an instance
    // of the Solution class
    Solution solution;
    // Perform preorder traversal
    bool result = solution.isBalanced(root);

    if (result)
    {
        cout << "The binary tree is height-balanced." << endl;
    }
    else
    {
        cout << "The binary tree is not height-balanced." << endl;
    }

    return 0;
}