/*
Approach:
    1. iterate the array and insert into the set
    2. add set size into answer.
*/

class Solution
{
public:
    vector<int> prefixDistinct(int n, vector<int> &arr)
    {
        // Write your code here.
        set<int> st;
        vector<int> ans;
        for (auto x : arr)
        {
            st.insert(x);
            ans.push_back(st.size());
        }
        return ans;
    }
};
