/*
GeeksForGeeks-POTD: Minimum element in BST

POTD Link: https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

Approach:  
    1. traverse root, until root->left is not null

TimeComplexity: O(log(n))

*/

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
  
    // left most element is the smallest in BST
    int minValue(Node* root) {
        if(!root)
            return -1;
        while(root->left)
            root = root->left;
        
        return root->data;
    }
};
