/*

Approach:
    1. Initialize a map m to store the last occurrence index of each element.
    2. from every index, calculate the longest jump,
    3. update ans to max(ans, n - jump)

*/

class Solution
{
public:
    int minJumps(int n, vector<int> &v)
    {
        map<int, int> mp;
        // store the last occurence
        for (int i = 0; i < n; i++)
        {
            mp[v[i]] = i;
        }

        int ans = n - 1;
        for (int i = 0; i < n; i++)
        {
            // the longest jump from this point
            int jump = mp[v[i]] - i;
            ans = min(ans, n - jump);
        }
        return ans;
    }
};
