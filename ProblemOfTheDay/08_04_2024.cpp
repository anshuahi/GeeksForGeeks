/*
GeeksForGeeks-POTD: Optimal Strategy For A Game

POTD Link: https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

Approach:
    1. try all possible combinations of coin picks, considering that the opposing player also plays optimally
    2. store the answer in the dp

TimeComplexity: O(N*N)
SpaceComplexity: O(N*N)

*/
#define ll long long
class Solution
{
public:
    ll dp[1001][1001];
    ll solve(int st, int en, vector<ll> &prefSum)
    {
        ll rangeSum = (st == 0) ? prefSum[en] : prefSum[en] - prefSum[st - 1];
        if (st == en)
        {
            return rangeSum;
        }
        if (dp[st][en] != -1)
        {
            return dp[st][en];
        }
        ll first = rangeSum - solve(st + 1, en, prefSum);
        ll last = rangeSum - solve(st, en - 1, prefSum);
        return dp[st][en] = max(first, last);
    }

    long long maximumAmount(int n, int arr[])
    {
        memset(dp, -1, sizeof dp);
        vector<ll> prefSum(n);
        prefSum[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefSum[i] = prefSum[i - 1] + arr[i];
        }
        return solve(0, n - 1, prefSum);
    }
};
