/*
GeeksForGeeks-POTD: Modular Exponentiation for large numbers

POTD Link: https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1

Approach
    1. divide and conquer
    2. find PowMod(x, n/2, M) and square it, if n is odd multiply the result with x

*/

class Solution
{
	public:
	    #define ll long long
		ll PowMod(ll x, ll n, ll M){
		    if(n == 0) return 1%M;
		    
		    long long int p = PowMod(x, n/2, M);
		    p = (p*p)%M;
		    if(n%2 == 1) 
		        p = p*x;
		    
		    return p%M;
		}
};
