/*
GeeksForGeeks-POTD: Vertical sum

POTD Link: https://www.geeksforgeeks.org/problems/vertical-sum/1

Approach
    1. traverse all nodes, with level
    2. add node value to map with respective level
    3. recursively traverse, root->left with level-1 and root->right with level+1

*/
/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution
{
public:
    map<int, int> mp;
    void traverse(Node *root, int level)
    {
        if (!root)
            return;
        mp[level] += root->data;
        traverse(root->left, level - 1);
        traverse(root->right, level + 1);
    }

    vector<int> verticalSum(Node *root)
    {
        traverse(root, 0);
        vector<int> a;
        for (auto x : mp)
        {
            a.push_back(x.second);
        }

        return a;
    }
};
