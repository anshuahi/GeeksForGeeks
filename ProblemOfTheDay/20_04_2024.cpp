/*
GeeksForGeeks-POTD: Union of Two Sorted Arrays

POTD Link: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

Approach
    1. use set

TimeComplexity: O(N+M)
SpaceComplexity: O(N+M)

*/

class Solution
{
public:
    // arr1,arr2 : the arrays
    //  n, m: size of arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        set<int> st;
        for (int i = 0; i < n; i++)
            st.insert(arr1[i]);
        for (int i = 0; i < m; i++)
            st.insert(arr2[i]);

        for (auto x : st)
        {
            ans.push_back(x);
        }

        return ans;
    }
};