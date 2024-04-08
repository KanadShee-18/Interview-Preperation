//// Height Of Binary Tree: or
/// Maximum Depth of a Binary Tree
// ~~~~~~~~~~~~~~~~~~~~~~~~~

// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
    // TC -> O(n) and SC -> O(n)
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
    int result = solution.maxDepth(root);

    cout << "The height of the binary tree is: " << result << endl;
    return 0;
}
