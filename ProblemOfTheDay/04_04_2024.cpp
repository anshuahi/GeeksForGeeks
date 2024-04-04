/*
GeeksForGeeks-POTD: Sum of all substrings of a number

POTD Link: https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

GitHub Solution Link- https://github.com/anshuahi/GeeksForGeeks/blob/master/ProblemOfTheDay/04_04_2024.cpp

TimeComplexity: O(N)
SpaceComplexity: O(N)

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
