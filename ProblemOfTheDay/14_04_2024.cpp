/*
GeeksForGeeks-POTD: Xoring and Clearing

POTD Link: https://www.geeksforgeeks.org/problems/xoring-and-clearing/1

*TimeComplexity*: O(N)
*SpaceComplexity*: O(1)

*/

class Solution
{
public:
    void printArr(int n, int arr[])
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

    void setToZero(int n, int arr[])
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }
    }

    void xor1ToN(int n, int arr[])
    {
        // Xor arr[i]^i
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] ^ i;
        }
    }
};
