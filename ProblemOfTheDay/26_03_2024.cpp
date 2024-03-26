/*
    GeeksForGeeks: Additive sequence
    POTD Link - https://www.geeksforgeeks.org/problems/additive-sequence/1

    Approach: 
        1. generate all possible two numbers from the string(num1, num2) 
           such that string(num1) + string(num2) are prefix of the string;
        2. check the third number starting from the index where num2 ends, 
           and keep checking till the end of string.
*/

class Solution {
  public:
    bool checkNextNum(string &s, int idx, int num1, int num2){
        int n = s.size();
        if(idx == n)
            return true;
        int num3 = 0;
        while(idx < n){
            // generate all possible numbers starting with index idx
            num3 = num3*10 + (s[idx++] - '0');
            if(num3 == num1 + num2){
                return checkNextNum(s, idx, num2, num3);
            }
            if(num3 > num1 + num2){
                break;
            }
        }
        return false;
    }
    
    bool isAdditiveSequence(string s) {
        int n = s.size();
        int num1 = 0, num2 = 0;
        for(int i = 0; i < n-2; i++){
            // generate first number
            num1 = num1*10 + (s[i]-'0');
            num2 = 0;
            for(int j = i+1; j < n-1; j++){
                // generate second number
                num2 = num2*10 + (s[j]-'0');
                // checking if the series continues with num1 and num2.
                if(checkNextNum(s, j+1, num1, num2)){
                    return true;
                }
            }
        }
        return false;
    }
};