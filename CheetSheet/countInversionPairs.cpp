#include <bits/stdc++.h>

class CountInversionPairs
{
    vector<int> v, temp;

public:
    CountInversionPairs(vector<int> arr)
    {
        this->v = arr;
        this->temp = arr;
    }
    int merge(int st, int mid, int en)
    {
        int i = st, j = mid;
        int k = st;

        int invPairs = 0;
        while (i <= mid - 1 && j <= en)
        {
            if (v[i] > v[j])
            {
                temp[k++] = v[j++];
                invPairs += (mid - i);
            }
            else
            {
                temp[k++] = v[i++];
            }
        }
        while (i <= mid - 1)
        {
            temp[k++] = v[i++];
        }
        while (j <= en)
        {
            temp[k++] = v[j++];
        }

        for (int k = st; k <= en; k++)
        {
            v[k] = temp[k];
        }

        return invPairs;
    }

    int mergeSort(int st, int en)
    {
        if (st == en)
            return 0;
        int invPairs = 0;
        int mid = (st + en) / 2;
        invPairs += mergeSort(st, mid);
        invPairs += mergeSort(mid + 1, en);

        invPairs += merge(st, mid + 1, en);

        return invPairs;
    }

    int countInversionPairs()
    {
        int count = mergeSort(0, v.size() - 1);
        return count;
    }
};
