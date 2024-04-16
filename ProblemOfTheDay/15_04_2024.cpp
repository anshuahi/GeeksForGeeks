/*
GeeksForGeeks-POTD: Count the elements

POTD Link: https://www.geeksforgeeks.org/problems/count-the-elements1529/1

GitHub Solution Link- https://github.com/anshuahi/GeeksForGeeks/blob/master/ProblemOfTheDay/15_04_2024.cpp
Approach
    1. sort the first array
    2. use upper_bound in the first array to count element less than b[i]

TimeComplexity: O(NlogN)
SpaceComplexity: O(N)

*/
class Solution
{
public:
    vector<int> countElements(vector<int> &a, vector<int> &b,
                              int n, vector<int> &query, int q)
    {
        sort(b.begin(), b.end());
        vector<int> ans;
        for (auto q : query)
        {
            auto lo = upper_bound(b.begin(), b.end(), a[q]);
            int count = lo - b.begin();
            ans.push_back(count);
        }
        return ans;
    }
};
