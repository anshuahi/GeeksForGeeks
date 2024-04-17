/*
GeeksForGeeks-POTD: Count Pairs in an Array

POTD Link: https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1

Approach
    1. create new array with i*arr[i]
    2. count inversion pair
TimeComplexity: O(NlogN)
SpaceComplexity: O(N)

*/

class Solution
{
public:
    int merge(vector<int> &v, vector<int> &temp, int st, int mid, int en)
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

    int mergeSort(vector<int> &v, vector<int> &temp, int st, int en)
    {
        if (st == en)
            return 0;
        int invPairs = 0;
        int mid = (st + en) / 2;
        invPairs += mergeSort(v, temp, st, mid);
        invPairs += mergeSort(v, temp, mid + 1, en);

        invPairs += merge(v, temp, st, mid + 1, en);

        return invPairs;
    }

    int countInversionPairs(vector<int> &v)
    {
        int n = v.size();
        vector<int> temp(n);
        int count = mergeSort(v, temp, 0, n - 1);
        return count;
    }
    int countPairs(int arr[], int n)
    {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = i * arr[i];
        }
        CountInversionPairs cip = new CountInversionPairs(v);
        return cip.countInversionPairs();

        return countInversionPairs(v);
    }
};
