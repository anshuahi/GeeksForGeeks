/*
GeeksForGeeks-POTD: Maximum sum of hour glass

POTD Link: https://www.geeksforgeeks.org/problems/maximum-sum-of-hour-glass3842/1

Approach
    1. calculate all hourGlassSum
    2. return maximum hourGlassSum
*/

class Solution
{
public:
    int hourGlassSum(vector<vector<int>> &mat, int i, int j)
    {
        return mat[i][j] + mat[i - 1][j - 1] + mat[i - 1][j] +
               mat[i - 1][j + 1] + mat[i + 1][j - 1] +
               mat[i + 1][j] + mat[i + 1][j + 1];
    }
    int findMaxSum(int n, int m, vector<vector<int>> mat)
    {
        if (n < 3)
            return -1;
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                ans = max(ans, hourGlassSum(mat, i, j));
            }
        }

        return ans;
    }
};
