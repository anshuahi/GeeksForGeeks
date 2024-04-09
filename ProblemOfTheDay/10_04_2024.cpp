/*
GeeksForGeeks-POTD: Minimum Points To Reach Destination

POTD Link: https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1

Approach:
    1. Initialization: Initialize a 2D array dp of size (M+1) x (N+1) with all values set to -1. This array will store the minimum points required to reach the destination from each cell.
    2. Recursive Function: Define a recursive function helperFunction to calculate the minimum points required to reach the destination from a given cell (x, y).
    3. Base Cases:
        If the current cell is the destination (M-1, N-1), return 1 if the points in the cell are positive, else return 1 + abs(points[x][y]).
        If either x or y exceeds the grid boundaries, return positive infinity as it's not possible to reach the destination from such cells.
    4. Memoization:
        Check if the minimum points required to reach the destination from the current cell (x, y) are already calculated. If yes, return the stored value from the dp array.
    5. Recursive Calls:
        Make recursive calls for moving down (x+1, y) and moving right (x, y+1).
        Calculate the minimum points required from these two options and subtract the points of the current cell from it. This gives the minimum points required to move to the next cell while ensuring positive points.
    6. Store Result:
        Store the result in the dp array for future reference and return it.
    7. Final Result:
        Call the helperFunction with the starting cell (0, 0) and return the result.
    8. Return Minimum Points:
        The minimum points required to reach the destination from the starting cell will be the result obtained from the helperFunction.

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
