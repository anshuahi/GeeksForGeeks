/*
GeeksForGeeks-POTD: Paths to reach origin

POTD Link: https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1

Approach
    1. recursive solution, ways(x, y) = ways(x-1, y) + ways(x, y-1)
    2. base condition: ways(0, 0) = 1
*/

class Solution
{
public:
    int M = 1000000007;
    int countWays(int x, int y, vector<vector<long>> &dp)
    {
        if (x < 0 || y < 0)
            return 0;

        if (dp[x][y] != -1)
            return dp[x][y];

        dp[x][y] = (countWays(x - 1, y, dp) + countWays(x, y - 1, dp)) % M;
        return dp[x][y];
    }

    int ways(int x, int y)
    {
        vector<vector<long>> dp(x + 1, vector<long>(y + 1, -1));
        dp[0][0] = 1;
        return countWays(x, y, dp);
    }
};
