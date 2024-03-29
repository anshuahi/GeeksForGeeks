/*
GeeksForGeeks POTD:
    Euler Circuit in an Undirected Graph

POTD Link:
    https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1

Approach:
    1. Euler circuit exists if degrees of all nodes are even
    2. check if degree of any node is odd, return 0. else return 1
*/


class Solution {
public:
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    
        for(int i = 0; i < v; i++){
            int degree = adj[i].size();
            // if degree of a node is odd, 
            if(degree%2 == 1)
                return 0;
        }
        
        return 1;
	}

};
