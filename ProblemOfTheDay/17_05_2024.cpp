/*
GeeksForGeeks-POTD: Find Pair Given Difference

POTD Link: https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1

Approach
    1. use Map/Set for storing the number
    2. find if num-x or num+x exists in map, return 1.

*/

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        map<int, int> mp;
        
        for(auto a: arr){
            if(mp.find(a-x) != mp.end() 
                || mp.find(a+x) != mp.end()) {
                return 1;
            }
            mp[a] = 1;
        }
        
        return -1;
    }
};
