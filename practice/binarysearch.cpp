#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int>arr,int key){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
 int mid=start+(end-start)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(key>arr[mid]){
        start=mid+1;
    }
    else{
        end=mid-1;
    }
   
    }
     return -1;
   
}
int main(){
    int n;
    cout<<"enter size of array";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    int key;
    cout<<"enter key to search";
    
     
}