/*
GeeksForGeeks-POTD: Sum of all substrings of a number

POTD Link: https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

GitHub Solution Link- https://github.com/anshuahi/GeeksForGeeks/blob/master/ProblemOfTheDay/04_04_2024.cpp

TimeComplexity: O(N)
SpaceComplexity: O(N)

Approach:
s = “1234”
dp[0] = 1 = 1
dp[1] = 2 + 12  = 14
dp[2] = 3 + 23  + 123 = 149
dp[3] = 4 + 34  + 234 + 1234  = 1506
Result = 1670
Now we can get the relation between dp values and can solve the question iteratively. Each dp value can be represented in terms of previous value as shown below, For above example,
dp[3] = 4 + 34 + 234 + 1234
    = 4 + 30 + 4 + 230 + 4 + 1230 + 4
    = 4*4 + 10*(3 + 23 +123)
    = 4*4 + 10*(dp[2])
In general, dp[i]  =  (i+1)*(s[i]-'0') + (10*dp[i-1]),  here (s[i]-'0') will convert s[i] character to its integer value.

*/

class Solution
{
public:
    int Mod = 1e9 + 7;

    // Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s)
    {

        int n = s.size();
        vector<long long> dp(n + 1);
        dp[0] = (s[0] - '0');
        long long ans = dp[0];
        for (int i = 1; i < n; i++)
        {
            int digit = (s[i] - '0');
            dp[i] = (1L * digit * (i + 1) + dp[i - 1] * 10) % Mod;
            ans += dp[i];
            ans = ans % Mod;
        }

        return ans;
    }
};
