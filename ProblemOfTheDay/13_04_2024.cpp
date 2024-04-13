/*
GeeksForGeeks-POTD: Reverse Bits

POTD Link: https://www.geeksforgeeks.org/problems/reverse-bits3556/1

Approach
    1. reverse every set bit value.

TimeComplexity: O(log(N))
SpaceComplexity: O(1)

*/

class Solution
{
public:
    long long reversedBits(long long x)
    {
        long long ans = 0;
        int i = 0;
        while (i < 32)
        {
            ans = ans * 2 + x % 2;
            x = x / 2;
            i++;
        }
        return ans;
    }
};
