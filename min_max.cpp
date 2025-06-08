#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
int mini(vector<int>arr){
    int min=arr[0];
    for(int i=0;i<arr.size();i++){
       
        if(arr[i]>min){
            min=arr[i];
        }
       
    }
    return min;

}
int kth_max(vector<int>arr,int k){
    int max;
    
    for(int i=0;i<k-1;i++){
         max=mini(arr);
         cout<<max<<" ";
         remove(arr.begin(), arr.end(), max);
         arr.pop_back();
    }
  int kmax=mini(arr);
  return kmax;
}
int main(){
    int n,input;
    int minimum,kmax;
    vector<int>arr;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input;
        arr.push_back(input);
    }
    
    // minimum=mini(arr);
    // cout<<minimum;
    
  kmax=kth_max(arr,4);
  cout<<kmax;
}