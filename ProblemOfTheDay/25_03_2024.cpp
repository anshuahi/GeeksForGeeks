/*
Question: https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

Approach:
    1. Start with string 10101010... and generate all string greater than this.
    2. check if all prefix has more or equal ones than zero and add it to answer list
*/

class Solution{
public:
    string generateNextStr(string s){
        int carry = 1;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '0'){
                s[i] = '1';
                return s;
            }
            s[i] = '0';
        }
        return s;
    }
    
    bool checkValidPrefixCount(string s){
        int ones = 0, zeros = 0;
        for(auto c: s){
            c == '1'? ones++ : zeros++;
            if(zeros > ones)
                return false;
        }
        return true;
    }
    
	vector<string> NBitBinary(int n){
	    vector<string> ans;
	    string firstStr = "", allZeros = "";
	    for(int i = 0; i < n; i++){
	        firstStr += (i%2 == 0)? '1' : '0';
	        allZeros += "0";
	    }
	    
	    while(firstStr != allZeros){
	        if(checkValidPrefixCount(firstStr))
	            ans.push_back(firstStr);
	        firstStr = generateNextStr(firstStr);
	    }
	    
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};