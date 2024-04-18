/*
GeeksForGeeks-POTD: Two Repeated Elements

POTD Link: https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1

GitHub Solution Link- https://github.com/anshuahi/GeeksForGeeks/blob/master/ProblemOfTheDay/18_04_2024.cpp

Approach
1. mark every arr[arr[i]] as negative,
2. if any arr[arr[i]] is already negative, it indicates the duplicate.

TimeComplexity: O(N)
SpaceComplexity: O(1)

*/

class Solution
{
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int arr[], int n)
    {

        vector<int> ans;
        for (int i = 0; i < n + 2; i++)
        {
            if (arr[abs(arr[i])] > 0)
            {
                arr[abs(arr[i])] = -arr[abs(arr[i])];
            }
            else
            {
                ans.push_back(abs(arr[i]));
            }
        }

        return ans;
    }
};
