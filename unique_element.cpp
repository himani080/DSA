#include<iostream>
#include<vector>
using namespace std;
int unique(vector<int>arr){
    int ans=0;
    for(int i=0;i<arr.size();i++){
        ans=ans^arr[i];
    }
    return ans;
}
int main(){
    int n,input;
    vector<int>arr;
    cout<<"enter size";
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>input;
      arr.push_back(input);
    }
    int ans=unique(arr);
    cout<<ans;
}