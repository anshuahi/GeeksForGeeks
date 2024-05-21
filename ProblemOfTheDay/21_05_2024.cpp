/*
GeeksForGeeks-POTD: K closest elements

POTD Link: https://www.geeksforgeeks.org/problems/k-closest-elements3619/1

Approach
    1. find the index(idx) of closest element using upper_bound
    2. take k element from idx on each side, idx-k to idx+k
    3. use minHeap on abs(arr[i]-x) for i in [idx-k, idx+k]
    4. choose k elements from minHeap,

*/
#define pii pair<int, int>
class Compare {
public:
    bool operator()(pii a, pii b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        int idx = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        vector<int> ans;
        int i = idx-1, j = idx;
        priority_queue<pii, vector<pii>, Compare> q;
        while(k > 0){
            if(0 <= j && j < n){
                q.push({abs(arr[j]-x), arr[j]});
                j++;
            }
            if(0 <= i && i < n){
                q.push({abs(arr[i]-x), arr[i]});
                i--;
            }
            
            pii p = q.top(); q.pop();
            if(p.first > 0){
                ans.push_back(p.second);
                k--;
            }
        }
        
        return ans;
    }
};
