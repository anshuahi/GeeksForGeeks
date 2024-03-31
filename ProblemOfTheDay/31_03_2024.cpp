/*
GeeksForGeeks-POTD: Closest Neighbour in BST

POTD Link: https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1

GitHub Solution Link- https://github.com/anshuahi/GeeksForGeeks/blob/master/ProblemOfTheDay/31_03_2024.cpp

*Approach:*  
    1. root->key is equal to n, return it.
    2. if root->key is less than n, update answer and find if any node is greater than ans exist in left subtree

*TimeComplexity*: O(height of tree)

*/

class Solution {
  public:
    int findMaxForN(Node* root, int n) {
        if(!root)
            return -1;
        int ans = -1;
        while(root){
            if(root->key == n)
                return n;
            if(root->key < n){
                ans = root->key;
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        return ans;
    }
};