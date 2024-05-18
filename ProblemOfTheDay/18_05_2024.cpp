/*
GeeksForGeeks-POTD: Find the Highest number

POTD Link: https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1

Approach
    1. binary search

*/

class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int l = 0, r = a.size()-1;
        
        while(l < r){
            int mid = (l+r)/2;
            if(a[mid] > a[mid+1]){
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        
        return a[l];
    }
};
