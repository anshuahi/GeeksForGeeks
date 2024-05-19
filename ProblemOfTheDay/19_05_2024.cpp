/*
GeeksForGeeks-POTD: Find the closest number

POTD Link: https://www.geeksforgeeks.org/problems/find-the-closest-number5513/1

Approach
    1. binary search(upper_bound)

*/

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) { 
        int idx = upper_bound(arr, arr+n, k) - arr;
        int d1 = 1e9, d2=1e9;
        if(idx<n){
            d1 = abs(k-arr[idx]);
        }
        if(idx>0){
            d2 = abs(k-arr[idx-1]);
        }
        return d1<=d2? arr[idx] : arr[idx-1];
    } 
};
