#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define M 1000000007

ll solve(int idx, vector<int> &v, int n, int k, vector<vector<int>> &dp)
{
    if (idx >= n)
    {
        return 1;
    }
    // if(idx == n-1){}
    int mn = v[idx], mx = v[idx];

    ll ans = 0;
    for (int i = idx; i < n; i++)
    {
        mx = max(v[i], mx);
        if (mx - mn > k)
        {
            break;
        }
        ans += solve(i + 1, v, n, k, dp);
    }

    return ans;
}

#define pii pair<string, string>

pii split(string s)
{
    // if
    string a = "", b;
    int idx = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.substr(i, 4) == " vs ")
        {
            a = s.substr(0, i);
            b = s.substr(i + 4);
        }
    }
    // cout << a << " " << b << endl;
    return {a, b};
}

int main()
{
    int n, k;
    // split("Stallion vs Rogue Rider");
    map<string, vector<string>> mp;
    string s;
    for (int i = 0; i < 45; i++)
    {
        getline(cin, s);
        // cout << s << " " << i << endl;
        pii p = split(s);
        mp[p.first].push_back(p.second);
        mp[p.second].push_back(p.first);
    }

    for (auto x : mp)
    {
        cout << x.first << " -> ";
        vector<string> v = x.second;
        sort(v.begin(), v.end());
        for (int i = 1; i < 9; i++)
        {
            // cout << p << ", ";
            if (v[i] == v[i - 1])
            {
                cout << "duplicate found";
            }
        }

        cout << v.size() << endl;
    }
    return 0;
}
