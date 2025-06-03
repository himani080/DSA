#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> decimaltobinary(int decimal){
    vector<int> ans;
    
   while(decimal>0){
    if(decimal%2==0){
        ans.push_back(0);
    }
    else{
        ans.push_back(1);
    }
    decimal=decimal/2;

   }
   reverse(ans.begin(), ans.end());
 return ans;
    
}
int main(){
    vector<int>result;
    int decimal;
    cin>>decimal;
    result=decimaltobinary(decimal);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}