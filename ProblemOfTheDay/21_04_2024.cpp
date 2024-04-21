/*
GeeksForGeeks-POTD: Three way partitioning

POTD Link: https://www.geeksforgeeks.org/problems/three-way-partitioning/1

*Approach*
1. move smaller elements to start and move larger element to end

*TimeComplexity*: O(N)
*SpaceComplexity*: O(1)
*/

#define pb push_back
class Solution
{
public:
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        // brute force solution
        // sort(array.begin(), array.end());
        int n = array.size();
        int st = 0, en = n - 1;
        for (int i = 0; i <= en;)
        {
            if (array[i] < a)
            {
                swap(array[i], array[st]);
                i++, st++;
            }
            else if (array[i] > b)
            {
                swap(array[i], array[en]);
                en--;
            }
            else
            {
                i++;
            }
        }
    }
};
