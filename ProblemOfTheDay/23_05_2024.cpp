/*
GeeksForGeeks-POTD: K-Palindrome

POTD Link: https://www.geeksforgeeks.org/problems/find-if-string-is-k-palindrome-or-not1923/1

Approach
    1. find the minimum number of characters need to be removed to make the string palindrome
    2. return ans <= k

*/
class Solution
{
public:
    int solve(string &s, int st, int en, vector<vector<int>> &dp)
    {
        if (st == en || st > en)
            return 0;
        if (dp[st][en] != -1)
            return dp[st][en];
        int a = solve(s, st + 1, en, dp);
        int b = solve(s, st, en - 1, dp);
        int ans = min(a, b) + 1;
        if (s[st] == s[en])
        {
            ans = min(ans, solve(s, st + 1, en - 1, dp));
        }

        return dp[st][en] = ans;
    }
    int kPalindrome(string str, int n, int k)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = solve(str, 0, n - 1, dp);
        return ans <= k;
    }
};
