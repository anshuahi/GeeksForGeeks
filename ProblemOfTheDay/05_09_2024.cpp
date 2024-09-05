
class Solution
{
public:
    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int> &arr)
    {
        // sum of numbers from 1 to n
        int sum = n * (n + 1) / 2;
        // sum of numbers in array
        int arr_sum = 0;
        for (auto x : arr)
            arr_sum += x;

        // missing Number is sum - arr_sum
        return sum - arr_sum;
    }
};
