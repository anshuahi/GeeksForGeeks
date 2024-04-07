/*

Approach:
    1. try Union-Find.
    2. Union of consecutive cities with same beautifulness
    3. check if query cities have same parent.

*/

class Solution
{
public:
    void Union(int a, int b, vector<int> &par)
    {
        int x = find(a, par);
        int y = find(b, par);
        par[x] = y;
        par[a] = y;
        par[b] = y;
    }

    int find(int a, vector<int> &par)
    {
        if (a == par[a])
            return a;
        return par[a] = find(par[a], par);
    }

    vector<int> canTrade(int n, vector<int> &b, int q, vector<vector<int>> &queries)
    {
        vector<int> par(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
        }
        for (int i = 1; i < n; i++)
        {
            if (b[i] == b[i - 1])
            {
                Union(i, i - 1, par);
            }
        }
        vector<int> ans;
        for (auto q : queries)
        {
            int x = q[0] - 1, y = q[1] - 1;
            int p1 = find(x, par);
            int p2 = find(y, par);
            ans.push_back(p1 == p2);
        }
        return ans;
    }
};
