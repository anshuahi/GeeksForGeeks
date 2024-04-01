/*
GeeksForGeeks-POTD: Pairs violating the BST property

POTD Link: https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1

Approach: 
    1. find inorder of BST, 
    2. count inversion pairs in the inorder vector
*/
/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
  
    int merge(vector<int> &v, vector<int> &temp, int st, int mid, int en) {
        int i = st, j = mid;
        int k = st;
        
        int invPairs = 0;
        while(i <= mid-1 && j <= en){
            if(v[i] > v[j]){
                temp[k++] = v[j++];
                invPairs += (mid - i);
            }
            else {
                temp[k++] = v[i++];
            }
        }
        while(i <= mid-1){
            temp[k++] = v[i++];
        }
        while(j <= en){
            temp[k++] = v[j++];
        }
        
        for(int k = st; k <= en; k++){
            v[k] = temp[k];
        }
        
        return invPairs;
    }
  
    int mergeSort(vector<int> &v, vector<int> &temp, int st, int en){
        if(st == en)
            return 0;
        int invPairs = 0;
        int mid = (st+en)/2;
        invPairs += mergeSort(v, temp, st, mid);
        invPairs += mergeSort(v, temp, mid+1, en);
        
        invPairs += merge(v, temp, st, mid+1, en);
        
        return invPairs;
    }
  
    int countInversionPairs(vector<int> &v){
        int n = v.size();
        vector<int> temp(n);
        int count = mergeSort(v, temp, 0, n-1);
        return count;
    }

    void inorder(Node* root, vector<int> &v){
        if(!root)
            return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    int pairsViolatingBST(int n, Node *root) {
        vector<int> v;
        inorder(root, v);
        int ans = countInversionPairs(v);
        return ans;
    }
};