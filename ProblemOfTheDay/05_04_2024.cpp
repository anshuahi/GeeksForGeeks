/*


GeeksForGeeks-POTD: Strictly Increasing Array

POTD Link: https://www.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1

Approach
     1. Find the LIS(Longest Increasing subsequence) where a[i] > a[j] and a[i]-a[j] >= i-j

TimeComplexity: O(N*N)
SpaceComplexity: O(N)

*/
class Solution
{
public:
     // Iterative Solution
     int min_operations(vector<int> &nums)
     {
          int n = nums.size();
          vector<int> dp(n + 1, 1);
          int lis = 1;
          for (int i = 1; i < n; i++)
          {
               int temp = 0;
               for (int j = 0; j < i; j++)
               {
                    if (nums[i] - nums[j] >= i - j)
                    {
                         temp = max(temp, dp[j] + 1);
                    }
               }
               dp[i] = max(dp[i], temp);
               lis = max(lis, dp[i]);
          }

          return n - lis;
     }
};

class Solution1
{
public:
     int dp[1001][1010];
     int solve(int i, int pre, int n, vector<int> &nums)
     {
          if (i == n)
          {
               return 0;
          }
          if (dp[i][pre + 1] != -1)
          {
               return dp[i][pre + 1];
          }
          int ans = 0;
          if (pre == -1)
          {
               ans = max(ans, 1 + solve(i + 1, i, n, nums));
          }
          if (pre != -1 && nums[i] > nums[pre] && nums[i] - nums[pre] >= i - pre)
          {
               ans = max(ans, 1 + solve(i + 1, i, n, nums));
          }
          ans = max(ans, solve(i + 1, pre, n, nums));
          return dp[i][pre + 1] = ans;
     }

     int min_operations(vector<int> &nums)
     {
          int n = nums.size();
          int ans = 0;
          memset(dp, -1, sizeof dp);
          return n - solve(0, -1, n, nums);
          return ans;
     }
};