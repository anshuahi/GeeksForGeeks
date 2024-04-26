/*
GeeksForGeeks-POTD: Exit Point in a Matrix

POTD Link: https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1

Approach
    1. follow the steps mentioned in the question description

*/

class Solution
{
public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>> &matrix)
    {
        int i = 0, j = 0;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int currDir = 0;
        if (matrix[0][0] == 1)
        {
            currDir++;
            i += dir[currDir][0];
            j += dir[currDir][1];
        }

        while (true)
        {
            if (i < 0 || j < 0 || i >= n || j >= m)
            {
                i -= dir[currDir][0];
                j -= dir[currDir][1];
                return {i, j};
            }
            if (matrix[i][j] == 1)
            {
                matrix[i][j] = 0;
                currDir = (currDir + 1) % 4;
            }
            i += dir[currDir][0];
            j += dir[currDir][1];
        }
        return {};
    }
};
