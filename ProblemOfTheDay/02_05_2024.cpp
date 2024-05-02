/*
GeeksForGeeks-POTD: Serialize and deserialize a binary tree

POTD Link: https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

A binary tree node has data, pointer to left child and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

#define pb push_back

class Solution
{
public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        if (!root)
            return {0};
        vector<int> l = serialize(root->left);
        vector<int> r = serialize(root->right);
        int count = l.size() + r.size() + 1;
        vector<int> ans;
        ans.pb(count);
        ans.pb(root->data);
        for (auto x : l)
            ans.pb(x);
        for (auto x : r)
            ans.pb(x);
        return ans;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        if (A.size() == 0 || A[0] == 0)
        {
            return NULL;
        }
        Node *root = new Node(A[1]);

        vector<int> l, r;
        int i = 0, j = 2;
        while (i <= A[2])
        {
            l.pb(A[j++]);
            i++;
        }
        while (j < A.size())
        {
            r.pb(A[j++]);
        }

        root->left = deSerialize(l);
        root->right = deSerialize(r);

        return root;
    }
};