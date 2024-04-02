/*

GeeksForGeeks-POTD: Minimum Absolute Difference In BST

POTD Link: https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1

Approach: 
    1. Use inorder of BST, 
    2. compare root->data to value coming from inorder of root->left.

TimeComplexity: O(n)

*/
class Solution
{
    public:
    void inorder(Node* root, int &val, int &minDiff){
        if(root->left){
            inorder(root->left, val, minDiff);
        }
        if(val >= 0){
            minDiff = min(minDiff, root->data - val);
        }
        val = root->data;
        if(root->right){
            inorder(root->right, val, minDiff);
        }
    }
    int absolute_diff(Node *root){
        if(!root)
            return 0;
        int minDiff = INT_MAX, val = -1;
        inorder(root, val, minDiff);
        return minDiff;
    }
};

