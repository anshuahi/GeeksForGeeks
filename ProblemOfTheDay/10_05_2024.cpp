/*
GeeksForGeeks-POTD: Combination Sum II

POTD Link: https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1

Approach
    1. sort the array
    2. try all combinations
    3. use backtracking with base conditions(rem == 0 and rem < 0 || idx >= n)

*/
class Solution
{
public:
    set<vector<int>> st;
    void solve(int idx, vector<int> &arr, vector<int> &v, int rem)
    {
        int n = arr.size();
        if (rem == 0)
        {
            st.insert(v);
            return;
        }
        if (rem < 0 || idx >= n)
            return;
        v.push_back(arr[idx]);
        solve(idx + 1, arr, v, rem - arr[idx]);
        v.pop_back();
        solve(idx + 1, arr, v, rem);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
    {
        vector<int> v;
        sort(arr.begin(), arr.end());
        solve(0, arr, v, k);
        vector<vector<int>> ans;
        for (auto x : st)
        {
            ans.push_back(x);
        }
        return ans;
    }
};
