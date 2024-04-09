/*
GeeksForGeeks-POTD: Minimum Points To Reach Destination

POTD Link: https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1

TimeComplexity: O(N*N)
SpaceComplexity: O(N*N)
*/

class Solution
{

public:
    int minPoints(int m, int n, vector<vector<int>> points)
    {

        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                {
                    dp[i][j] = max(1, 1 - points[i][j]);
                }
                else if (i == m - 1)
                {
                    dp[i][j] = max(1, dp[i][j + 1] - points[i][j]);
                }
                else if (j == n - 1)
                {
                    dp[i][j] = max(1, dp[i + 1][j] - points[i][j]);
                }
                else
                {
                    dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - points[i][j]);
                }
            }
        }

        return dp[0][0];
    }
};
