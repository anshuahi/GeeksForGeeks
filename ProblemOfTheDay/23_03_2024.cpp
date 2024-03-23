// ------ Fibonacci series up to Nth term ------------
// Question Link- https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1

class Solution {
  public:
    int M = 1000000007;
    vector<int> Series(int n) {
        if(n == 1){
            return {0, 1};
        }
        vector<int> fib = {0, 1};
        for(int i = 2; i <= n; i++){
            // next term = sum of last two terms
            int nextTerm = (fib[i-1]+fib[i-2])%M;
            fib.push_back(nextTerm);
        }
        
        return fib;
    }
};
