/// Binary Tree Traversals:

#include <bits/stdc++.h>
using namespace std;

struct Node
{

    // Defining value of the node.
    int data;

    // Left reference ptr to the node.
    struct Node *left;

    // Right reference ptr to the node.
    struct Node *right;

    // Method to initialize the above values.
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Implementation of Inorder Traversal
void inOrderTrav(Node *curr, vector<int> &inOrder)
{
    if (curr == NULL)
        return;

    inOrderTrav(curr->left, inOrder);
    inOrder.push_back(curr->data);
    inOrderTrav(curr->right, inOrder);
}

// Implementation of Preorder Traversal
void preOrderTrav(Node *curr, vector<int> &preOrder)
{
    if (curr == NULL)
        return;

    preOrder.push_back(curr->data);
    preOrderTrav(curr->left, preOrder);
    preOrderTrav(curr->right, preOrder);
}

// Implementation of Postorder Traversal
void postOrderTrav(Node *curr, vector<int> &postOrder)
{
    if (curr == NULL)
        return;

    postOrderTrav(curr->left, postOrder);
    postOrderTrav(curr->right, postOrder);
    postOrder.push_back(curr->data);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    return 0;
}