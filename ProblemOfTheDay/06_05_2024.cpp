/*
GeeksForGeeks-POTD: Print all nodes that don't have sibling

POTD Link: https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1

Approach
    1. traverse all nodes recursively,
    2. if a node has only one child, add its only child to the answer list

*/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

void solve(Node *root, vector<int> &v)
{
    if (!root)
        return;
    if (root->left && root->right)
    {
        solve(root->left, v);
        solve(root->right, v);
        return;
    }

    if (root->left)
    {
        v.push_back(root->left->data);
        solve(root->left, v);
    }

    if (root->right)
    {
        v.push_back(root->right->data);
        solve(root->right, v);
    }
}

vector<int> noSibling(Node *node)
{
    if (!node)
        return {-1};
    vector<int> v;
    solve(node, v);
    sort(v.begin(), v.end());
    if (v.size() == 0)
        return {-1};
    return v;
}
