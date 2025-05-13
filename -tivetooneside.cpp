#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
 void shifting(vector<int>&arr){
    vector<int>negative;
    for(int i=0;i<arr.size();i++){
         
      if(arr[i]<0){
        int neg=arr[i];
        negative.push_back(neg);
        arr.erase(arr.begin() + i);
        i--;  
      }
    }
    for(int i=0;i<negative.size();i++){
        arr.push_back(negative[i]);
    }
 }
 int main(){
    int n,input;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>input;
        arr.push_back(input);
    }
    shifting(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i];
    }
 }
