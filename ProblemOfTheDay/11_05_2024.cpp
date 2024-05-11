/*
GeeksForGeeks-POTD: Juggler Sequence

POTD Link: https://www.geeksforgeeks.org/problems/juggler-sequence3930/1

Approach
    1. use while loop until n becomes 1.
    2. if n is even, n = sqrt(n)
    3. else n = sqrt(n^3)
*/
class Solution
{
public:
    vector<long long> jugglerSequence(long long n)
    {
        // code here
        vector<long long> ans;
        while (n > 1)
        {
            ans.push_back(n);
            if (n % 2 == 0)
            {
                n = sqrt(n);
            }
            else
            {
                n = sqrt(1.0 * n * n * n);
            }
        }
        ans.push_back(n);

        return ans;
    }
};
