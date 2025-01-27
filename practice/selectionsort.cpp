#include<iostream>
#include<vector>
using namespace std;
void selectionsort(vector<int>arr){
    for(int i=0;i<arr.size()-1;i++){
        int minindex=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        swap(arr[minindex],arr[i]);
    }
}