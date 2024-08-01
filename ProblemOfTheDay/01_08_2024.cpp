/*
GeeksForGeeks-POTD: Spirally traversing a matrix

POTD Link: https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

Approach
1. set left, right, top, bottom
2. traverse j index from left to right, keeping i at top, at last increment top
3. traverse i index from top to bottom, keeping j at right, at last decrement right
4. traverse j index from right to left, keeping i at bottom, at last decrement top
5. traverse i index from bottom to top, keeping j at left, at last increment left

*/

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;

        while (top <= bottom && left <= right)
        {
            // go -> left to right
            for (int j = left; j <= right; j++)
                ans.push_back(matrix[top][j]);
            // update top
            top++;

            // go -> top to bottom
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            // update right
            right--;

            // special check if n is odd for top and bottom merge
            if (top > bottom || left > right)
                break;

            // go -> right to left
            for (int j = right; j >= left; j--)
                ans.push_back(matrix[bottom][j]);
            // update bottom
            bottom--;

            // go -> bottom to top
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            // update left
            left++;
        }

        return ans;
    }
};
