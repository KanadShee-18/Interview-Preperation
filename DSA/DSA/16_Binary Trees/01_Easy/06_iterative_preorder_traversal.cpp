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
    // Iterative: (using stack)
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preOrder;
        if (root == NULL)
            return preOrder;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            preOrder.push_back(node->val);
            if (node->right != NULL)
                st.push(node->right);
            if (node->left != NULL)
                st.push(node->left);
        }
        return preOrder;
    }
};

// Function to print
// the elements of a vector
void printVector(const vector<int> &vec)
{
    // Iterate through the
    // vector and print each element
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}

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
    vector<int> result = solution.preorderTraversal(root);

    cout << "Preorder Traversal of Tree: " << endl;

    // Printing the preorder traversal result
    printVector(result);

    return 0;
}
