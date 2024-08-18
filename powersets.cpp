#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int>&nums,int index,vector<int>&output,vector<vector<int>>&ans){
    //base case
    if(index>=nums.size()){
          ans.push_back(output);
          return ;

    }
    //exclude
    solve(nums,index+1,output,ans);
    //include
    int element=nums[index];
    output.push_back(element);
    solve(nums,index+1,output,ans);
    // output.pop_back();
}


vector <vector<int>> subsets(vector<int>&nums){
    vector<vector<int>> ans;
    int index=0;
    vector<int>output;
    solve(nums,index,output,ans);
    return ans;
}
int main()
{
    int n=3;
   vector<int>nums(n);
   vector<vector<int>> ans;
   for(int i=0;i<n;i++){
    cin>>nums[i];
   }
  ans= subsets(nums);
  cout << "Subsets:\n";
    for (const auto& subset : ans) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }
   
}