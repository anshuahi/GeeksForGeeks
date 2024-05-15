/*
GeeksForGeeks-POTD: Path With Minimum Effort

POTD Link: https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1

Approach
    1. binary search on answer
    2. use DFS

*/
class Solution
{
public:
    // int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
    //  code here
    bool possible(vector<vector<int>> &height, int k)
    {
        queue<pair<int, int>> q;
        q.push({0, 0});
        int n = height.size();
        int m = height[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i == n - 1 && j == m - 1)
                return true;
            if (i + 1 < n && abs(height[i][j] - height[i + 1][j]) <= k && !visited[i + 1][j])
            {
                visited[i + 1][j] = 1;
                q.push({i + 1, j});
            }
            if (j + 1 < m && abs(height[i][j] - height[i][j + 1]) <= k && !visited[i][j + 1])
            {
                visited[i][j + 1] = 1;
                q.push({i, j + 1});
            }
            if (i > 0 && abs(height[i][j] - height[i - 1][j]) <= k && !visited[i - 1][j])
            {
                visited[i - 1][j] = 1;
                q.push({i - 1, j});
            }
            if (j > 0 && abs(height[i][j] - height[i][j - 1]) <= k && !visited[i][j - 1])
            {
                visited[i][j - 1] = 1;
                q.push({i, j - 1});
            }
        }
        return false;
    }

    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
    {
        int start = 0, end = 1e6, ans = 1e6;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (possible(heights, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};
