/*
GeeksForGeeks-POTD: K distance from root

POTD Link: https://www.geeksforgeeks.org/problems/k-distance-from-root/1

Approach
    1. level order traversal using queue
    2. return if level == k

TimeComplexity: O(N)
SpaceComplexity: O(N)


//  A binary tree node has data, pointer to left child
    and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution
{
public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
        if (root == NULL)
        {
            return {};
        }

        queue<Node *> q;
        q.push(root);
        vector<int> v;

        int level = 0;
        while (!q.empty())
        {
            int len = q.size();
            v.clear();
            while (len--)
            {
                Node *p = q.front();
                q.pop();
                v.push_back(p->data);

                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            if (level == k)
                return v;
            level++;
        }
        return {};
    }
};
