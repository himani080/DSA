#include<iostream>
#include<vector>
using namespace std;
void merge(int start,int end,vector<int>arr){
    int mid=start+(end-mid)/2;
    int len1=mid-start+1;
    int len2=end-mid;
    int i=0;
    int j=0;
    int k=0;
    int minindex=0;
    vector<int>arr1;
    vector<int>arr2;
    minindex=start;
    for(int i=0;i<len1;i++){
        arr1[i++]=arr[minindex++];
    }
    minindex=mid+1;
    for(int i=0;i<len2;i++){
        arr2[i++]=arr[minindex++];
    }
    while(i<len1&&j<len2){
        if(arr1[i]<arr2[j]){
             arr[k++]=arr1[i++];
        }
        else{
            arr[k++]=arr2[j++];
        }
    }
     while(i<len1){
        arr[k++]=arr1[i++];
     }
     while(j<len2){
         arr[k++]=arr2[j++];
     }

}
void mergesort(int start,int end,vector<int>arr){
    int mid=start+(end-start)/2;
       if(start>=end){
        return;
       }
       mergesort(0,mid,arr);
       mergesort(mid+1,end,arr);
       merge(start,end,arr);
}