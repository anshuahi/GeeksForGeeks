/*
GeeksForGeeks-POTD: Find missing in second array

POTD Link: https://www.geeksforgeeks.org/problems/in-first-but-second5423/1

Approach
    1. store second array in a set
    2. check if element from first array exists in the set. if not, add it to ans vector

TimeComplexity: O(N+M)
SpaceComplexity: O(M)

*/

class Solution
{

public:
    vector<int> findMissing(int a[], int b[], int n, int m)
    {
        vector<int> ans;
        set<int> st;
        for (int i = 0; i < m; i++)
        {
            st.insert(b[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (st.find(a[i]) == st.end())
            {
                ans.push_back(a[i]);
            }
        }

        return ans;
    }
};
