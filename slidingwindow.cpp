class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r=0;
        int l=0;
        int n=nums.size();
        int maxlen=0;
        int temp=k;
        while(r<n){
            if(nums[r]==1){
                maxlen=max(maxlen,r-l+1);
                r++;
            }
            else{
                 if(temp!=0){
                    maxlen=max(maxlen,r-l+1);
                    r++;
                    temp=temp-1;
                 }   
                 else{
                    while(l<=r && temp==0){
                        if(nums[l]==0){
                            temp++;
                        }
                        l++;
                    }
                   
                 }    
            }
            
        }

        return maxlen;
    }
};