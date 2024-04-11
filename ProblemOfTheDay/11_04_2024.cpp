/*
GeeksForGeeks-POTD: Gray to Binary equivalent

POTD Link: https://www.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1

Approach https://docs.google.com/document/d/1JvuMcN8XXUP_bOiZmVvbNskWu4K2ieA0aoCJWAEexEM/edit
TimeComplexity: O(N)
SpaceComplexity: O(1)
*/

class Solution
{
public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    string intToBinary(int n)
    {
        string s = "";
        while (n > 0)
        {
            s += (n % 2 + '0');
            n = n / 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int grayToBinary(int n)
    {
        if (n < 2)
            return n;
        string binary = intToBinary(n);
        int ans = 1;
        int prevBit = 1;
        for (int i = 1; i < binary.size(); i++)
        {
            prevBit = prevBit ^ (binary[i] - '0');
            ans = ans * 2 + prevBit;
        }
        return ans;
    }
};
