/*
GeeksForGeeks-POTD: Row with minimum number of 1's

POTD Link: https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1

Approach
    1. count number of ones in each row and update the answer.
*/
class Solution
{
public:
    int minRow(int n, int m, vector<vector<int>> a)
    {
        int ans = 1;
        int ones = m;
        for (int i = 0; i < n; i++)
        {
            int countOnes = 0;
            for (int j = 0; j < m; j++)
            {
                countOnes += a[i][j];
            }
            if (countOnes < ones)
            {
                ones = countOnes;
                ans = i + 1;
            }
        }

        return ans;
    }
};
