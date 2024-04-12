/*

GeeksForGeeks-POTD: Sum of Products

POTD Link: https://www.geeksforgeeks.org/problems/sum-of-products5049/1


Approach
    1. make an array of prefix sum of each bit,
    2. if jth bit is set then add the prefixSum[j]*(1<<j) to ans

TimeComplexity: O(N)
SpaceComplexity: O(N)

*/
class Solution
{
public:
    long long pairAndSum(int n, long long arr[])
    {
        vector<long long> prefBitSum(32, 0);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                if ((arr[i] & (1 << j)) > 0)
                {
                    ans += prefBitSum[j] * (1 << j);
                    prefBitSum[j]++;
                }
            }
        }

        return ans;
    }
};
