/*
GeeksForGeeks-POTD: Count ways to N'th Stair

POTD Link: https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1

*Approach*
1.  The number of ways to reach ith step from (i-2)th step is just 1 extra.

*TimeComplexity*: O(N)
*SpaceComplexity*: O(N)

*/

class Solution
{
public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n)
    {
        // return (n+2)/2;
        if (n <= 2)
        {
            return n;
        }

        vector<long long> dp(n + 1);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 2] + 1;
        }

        return dp[n];
    }
};
