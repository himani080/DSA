#include<iostream>
#include<vector>
#include<string>
using namespace std;
void merge(int start,int end,string &arr){
	int n=arr.length();
    int mid=start+(end-start)/2;
	int l1=mid-start+1;
	int l2=end-mid;
	int mainindex=start;
	string arr1,arr2;
	for(int i=0;i<l1;i++){
		arr1[i]=arr[mainindex++];
	}
	mainindex=mid+1;
	for(int i=0;i<l2;i++){
		arr2[i]=arr[mainindex++];
	}
	mainindex=start;
	int i=0;
	int j=0;
	while(i<l1&&j<l2){
		if(arr1[i]<=arr2[j]){
			arr[mainindex++]=arr1[i++];
		}
		else{
			arr[mainindex++]=arr2[j++];
		}
	}
	while(i<l1){
		arr[mainindex++]=arr1[i++];
	}
		while(j<l2){
		arr[mainindex++]=arr2[j++];
	}
	
	
	
}
void mergesort(int start,int end,string &arr){
	int n=arr.length();
	int mid=start+(end-start)/2;
	if(start>=end){
		return;
	}
	mergesort(start,mid,arr);
	mergesort(mid+1,end,arr);
	merge(start,end,arr);
	
}
int main()
{
	string arr;
	cout<<"enter string";
	cin>>arr;
	int n=arr.length();
	mergesort(0,n-1,arr);
	cout<<arr;
	
}