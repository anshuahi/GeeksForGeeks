/*
GeeksForGeeks-POTD: Partitions with Given Difference

POTD Link: https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

Approach
1. count the number of subsets whose sum is equal to (target-d)/2

*/
class Solution {
  public:
  
    int M = 1e9+7;
    int solve(int i, int sum, vector<int> &arr, vector<vector<int>>& dp){
        if(i == 0){
            return sum == 0;
        }
        
        if(dp[i][sum] != -1) return dp[i][sum];
        int ans = solve(i-1, sum, arr, dp);
        if(sum >= arr[i-1])
            ans = (ans + solve(i-1, sum - arr[i-1], arr, dp))%M;
        return dp[i][sum] = ans;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum = 0;
        for(auto a: arr){
            totalSum += a;
        }
        
        if(totalSum < d || (totalSum - d)%2)
            return 0;
        
        int target = (totalSum - d)/2;
        vector<vector<int>> dp(n+1, vector<int>(2*target+1, -1));
        return solve(n, target, arr, dp);
    }
};
