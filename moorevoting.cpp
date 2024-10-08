#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;
        for(int num:nums){
            if(count==0){
                candidate=num;
            }
            count+=(candidate==num)?1:-1;
        }
        return candidate;
    }

};