/*
GeeksForGeeks-POTD: 
    Find shortest safe route in a matrix

POTD Link:
    https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1

Approach:
    1. Mark all the neighbors of mines as zero, as we can't reach there.
    2. BFS starting from first column to it's adjacent cell. and update the distance of each cell.
*/

#define pii pair<int, int>
#define ppii pair<int, pii>

class Solution
{
public:

    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
        
    bool isValidCell(int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return false;
        }
        return true;
    }
    
    // changing all neighbor cell of mines to zero
    vector<vector<int>> changeNeighborMineCells(vector<vector<int>> &mat){
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> matrix = mat;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    for(int idx = 0; idx < 4; idx++){
                        int newI = i+x[idx], newJ = j+y[idx];
                        if(isValidCell(newI, newJ, n, m)){
                            matrix[newI][newJ] = 0;
                        }
                    }
                }
            }
        }
        
        return matrix;
    }
    
    int findShortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> matrix = changeNeighborMineCells(mat);
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        queue<ppii> q;
        for(int i = 0; i < n; i++){
            if(matrix[i][0] == 1){
                q.push({1, {i, 0}});
                dp[i][0] = 1;
            }
        }
        int ans = INT_MAX;
    
        // DFS
        while(!q.empty()){
            ppii p = q.front(); q.pop();
            int i = p.second.first, j = p.second.second;
            int dist = p.first;
            if(matrix[i][j] == 0)
                continue;
            for(int idx = 0; idx < 4; idx++){
                int newI = i+x[idx], newJ = j+y[idx];
                if(isValidCell(newI, newJ, n, m) && dp[newI][newJ] > 1 + dist){
                    dp[newI][newJ] = 1 + dist;
                    q.push({dp[newI][newJ], {newI, newJ}});
                }
            }
        }
        
        for(int i = 0; i < n; i++){
           ans = min (ans, dp[i][m-1]);
        }
        return ans == INT_MAX? -1 : ans;
    }
};