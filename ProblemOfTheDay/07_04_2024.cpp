/*

GeeksForGeeks-POTD: Maximize dot product

POTD Link: https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1

Approach
1. explore all possible choices of inserting zeros in the second array while maintaining the order of elements
2. Use DP for memoization

Implementation
    1. Base Case: If i exceeds the size of array A, return 0.
    2. Initialization: Initialize ans to the minimum integer value.
    3. Check if Zeros Can be Inserted: If count is nonzero, recursively call solve by inserting zero in array B. Update ans with the maximum value between the current ans and the product of A[i] and 0 plus the result of the recursive call.
    4. Check if Array B is Exhausted: If j is less than m, meaning array B has elements remaining, recursively call solve with the current elements from arrays A and B. Update ans with the maximum value between the current ans and the product of A[i] and B[j] plus the result of the recursive call.
    5. Return the Result: Return ans, which stores the maximum dot product.
    6. Call the Recursive Function: In the maxDotProduct function, call solve with initial values of i, j, and count.
    7. Return the Result: Return the result obtained from the solve function.

TimeComplexity: O(N*M)
SpaceComplexity: O(N*M)
*/

class Solution
{

public:
    int solve(int i, int j, int n, int m, int a[], int b[], vector<vector<int>> &dp)
    {
        if (j == m)
            return 0;
        if (i == n)
            return INT_MIN;
        if (dp[i][j] != -1)
            return dp[i][j];
        // leave means inserting a zero at index j
        int leave = solve(i + 1, j, n, m, a, b, dp);
        int take = a[i] * b[j] + solve(i + 1, j + 1, n, m, a, b, dp);
        return dp[i][j] = max(leave, take);
    }

    int maxDotProduct(int n, int m, int a[], int b[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, n, m, a, b, dp);
    }
};
