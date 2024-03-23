// ------- POTD ZigZag Tree Traversal ------
// Question :  https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

#include <iostream>
#include <queue>
#include "tree.h"
using namespace std;

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector<int> solveUsingQueue(Node* root) {
        if(!root)
    	    return {};
    	vector<int> ans, temp;
    	queue<Node*> q;
    	q.push(root);
    	bool level = true;  // setting the even level as true, i.e. false means odd level
    	while(!q.empty()){
    	    int sz = q.size();
    	    temp.clear();
    	    //  traverse one layer at a time and store all the values in temp array;
    	    while(sz--){
    	        Node* node = q.front();
    	        q.pop();
    	        temp.push_back(node->data);
    	        if(node->left){
    	            q.push(node->left);
    	        }
    	        if(node->right){
    	            q.push(node->right);
    	        }
    	    }
    	    // if odd level, reverse the temp array;
    	    if(!level){ 
    	       reverse(temp.begin(), temp.end());
    	    }
    	    for(auto x: temp){
    	        ans.push_back(x);
    	    }
    	    level = !level;
    	}
    	
    	return ans;
    }
    
    vector<int> solveUsingStack(Node* root) {
        if(!root)
    	    return {};
    	    
    	vector<int> ans;
    	stack<Node*> st1, st2;
    	st1.push(root);
    	while(!st1.empty() || !st2.empty()){
    	    //  traverse one layer at a time and store all the values in ans array;
    	    while(!st1.empty()){
    	        Node* node = st1.top();st1.pop();
    	        ans.push_back(node->data);
    	        if(node->left){
    	            st2.push(node->left);
    	        }
    	        if(node->right){
    	            st2.push(node->right);
    	        }
    	    }
    	    while(!st2.empty()) {
    	        Node* node = st2.top(); st2.pop();
    	        ans.push_back(node->data);
    	        if(node->right){
    	            st1.push(node->right);
    	        }
    	        if(node->left)
    	            st1.push(node->left);
    	    }
    	}
    	
    	return ans;
    }
    
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	return solveUsingQueue(root); // solution 1
        // return solveUsingStack(root); // solution 2
    }};

int main(){
    return 0;
}