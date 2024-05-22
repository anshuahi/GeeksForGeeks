/*
GeeksForGeeks-POTD: Minimize Max Distance to Gas Station

POTD Link: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

Approach
    1. binary search on answer

*/

class Solution {
  public:
  
    bool check(vector<int> &stations, double d, int k){
        int n = stations.size();
        long req = 0;
        for(int i = 0; i < n-1; i++){
            double diff = 1.0*abs(stations[i+1] - stations[i]);
            long p = (diff*1.0/d);
            req += (p);
        }
        return req <= k;
    }
  
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        if(n == 1) return 0;
        double st = 0.0, en = 0;
        for(int i = 0; i < n-1; i++){
            en = max(en, 1.0*abs(stations[i] - stations[i+1]));
        }
        int p = 0;
        while(en - st > 0.00000001){
            double mid = (en + st)/2;
            if(check(stations, mid, k)){
                en = mid;
            }
            else {
                st = mid;
            }
        }
        return  en;
    }
};
