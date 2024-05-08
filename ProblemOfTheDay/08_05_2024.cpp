/*
GeeksForGeeks-POTD: Root to Leaf Paths

POTD Link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

Approach
    1. Traverse all nodes with DFS with node and list of all node-value of current path
    2. If leaf node, add to ans array

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> ans;
    void solve(Node *root, vector<int> &v)
    {
        if (!root)
            return;
        v.push_back(root->data);
        if (!root->left && !root->right)
        {
            ans.push_back(v);
            v.pop_back();
            return;
        }
        solve(root->left, v);
        solve(root->right, v);
        v.pop_back();
    }
    vector<vector<int>> Paths(Node *root)
    {
        if (!root)
            return {};
        vector<int> v;
        solve(root, v);

        return ans;
    }
};