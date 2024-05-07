/*
GeeksForGeeks-POTD: Reverse Level Order Traversal

POTD Link: https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1

Approach
    1. traverse all nodes recursively(first right child then left child), add the root to answer list
    2. reverse the answer list
*/
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    if (root == NULL)
        return {};
    queue<Node *> q;
    vector<int> ans;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        ans.push_back(root->data);
        if (root->right != NULL)
            q.push(root->right);
        if (root->left != NULL)
            q.push(root->left);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
