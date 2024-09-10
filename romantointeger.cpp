#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>roman={
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int result=0;
        int n=s.length();
        for(int i=n-1;i>=0;i--)
        {
            if(i<n-1&&roman[s[i]]<roman[s[i+1]]){
                   result-=roman[s[i]];     
            }
            else{
                 result+=roman[s[i]];
            }
        }
        
       return result;
    }
};