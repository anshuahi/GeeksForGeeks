/*
GeeksForGeeks-POTD: Rohan's Love for Matrix

POTD Link: https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1

Approach
    1. simple fibonacci series

*/

class Solution
{
public:
    int firstElement(int n)
    {
        if (n <= 2)
            return 1;
        long a = 1, b = 1, c = 1;
        int M = 1000000007;
        for (int i = 3; i <= n; i++)
        {
            c = a + b;
            a = b % M;
            b = c % M;
            c = c % M;
        }
        return c;
    }
};