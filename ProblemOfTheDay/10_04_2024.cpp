/*
GeeksForGeeks-POTD: Party of Couples

POTD Link: https://www.geeksforgeeks.org/problems/alone-in-couple5507/1

Approach
1. take the XOR of all elements of the array.

TimeComplexity: O(N)
SpaceComplexity: O(1)

*/

class Solution
{
public:
    int findSingle(int n, int arr[])
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans ^ arr[i];
        }

        return ans;
    }
};
