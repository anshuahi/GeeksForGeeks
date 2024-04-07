/*

Approach:
    1. binary search on the answer

*/

#define ll long long
#define pb push_back

class Solution
{
public:
    vector<ll> prefixSum;
    bool check(int r, int k, int n, ll mid)
    {
        vector<int> idx; // array of index where we increment
        vector<ll> val;  // array of increased value(must be less than or equal to k)
        for (int i = 0; i < n; i++)
        {
            int st = max(0, i - r), en = min(i + r, n - 1);
            ll rangeSum = (st == 0) ? prefixSum[en] : prefixSum[en] - prefixSum[st - 1];

            for (int j = 0; j < val.size(); j++)
            {
                if (st <= idx[j] && idx[j] <= en)
                {
                    rangeSum += val[j];
                }
            }

            if (rangeSum < mid)
            {
                if (k <= 0)
                {
                    return false;
                }
                ll diff = mid - rangeSum;
                if (diff > k)
                    return false;
                k -= diff;
                idx.pb(en);
                val.pb(diff);
            }
        }

        return true;
    }

    long long maxMinImportance(int n, int r, int k, vector<int> &arr)
    {
        ll st = 1, en = 1e11;
        prefixSum.resize(n);
        prefixSum[0] = arr[0];
        // prefixSum
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        // binary search on answer
        while (en - st > 1)
        {
            ll mid = (en + st) / 2;
            if (check(r, k, n, mid))
            {
                st = mid;
            }
            else
            {
                en = mid;
            }
        }

        return check(r, k, n, en) ? en : st;
    }
};
