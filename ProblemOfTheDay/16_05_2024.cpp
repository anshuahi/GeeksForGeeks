/*
GeeksForGeeks-POTD: Divisibility tree

POTD Link: https://www.geeksforgeeks.org/problems/divisibility-tree1902/1

Approach
    1. use dfs and count the nodes in its subtree
    2. if number of nodes in subtree is even, cut it i.e. increase answer
    3. else return number of nodes.
*/


class Solution {
public:
    
    int dfs(vector<vector<int>> &gr, int idx, int parent, int &ans) {
        int count = 1;
        
        for(auto node: gr[idx]){
            if(node != parent){
                count += dfs(gr, node, idx, ans);
            }
        }
        if(count%2 == 0){
            ans ++;
            return 0;
        }
        return count;
    }

	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    int ans = 0;
	    vector<vector<int>> gr(n+1);
	    for(auto e: edges){
	        gr[e[0]].push_back(e[1]);
	        gr[e[1]].push_back(e[0]);
	    }
	    
	    dfs(gr, 1, -1, ans);
	    
	    return ans-1;
	}
};
