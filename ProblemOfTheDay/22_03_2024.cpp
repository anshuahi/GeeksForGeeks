// ------- Diagonal sum in binary tree ------
// Question : https://www.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1
struct Node{
    int data;
    Node *left,*right;
};

class Solution
{
    public:
    
    void addDiagonalSum(Node* root, vector<int> &ans, int diagonal){
        if(!root)
            return;
        // if new diagonal found, insert it to the ans vector
        if(diagonal >= ans.size()){
            ans.push_back(root->data);
        }
        else {
            ans[diagonal] += root->data;
        }
        addDiagonalSum(root->left, ans, diagonal+1);
        addDiagonalSum(root->right, ans, diagonal);
    }
    
    vector<int> diagonalSum(Node* root) {
        vector<int> ans;
        addDiagonalSum(root, ans, 0);
        
        return ans;
    }
};
