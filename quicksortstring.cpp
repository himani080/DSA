#include<iostream>
#include<vector>
#include<string>
using namespace std;
void swap(char*a,char*b){
	char temp=*a;
	*a=*b;
	*b=temp;
	
}
int partition(int start,int end,string &arr){
	char pivot=arr[start];
	int count=0;
	for(int i=start+1;i<=end;i++){
		if(arr[i]<pivot){
			count++;
		}
	}
	int pivotindex=start+count;
	swap(&arr[start],&arr[pivotindex]);
	int i=start;
	int j=end;
	while(i<pivotindex&&j>pivotindex){
		while(arr[i]<=pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if(i<pivotindex&&j>pivotindex){
			swap(&arr[i++],&arr[j--]);
		}
	}

	return pivotindex;
}
void quicksort(int start,int end,string &arr){
	if(start>=end){
		return;
	}
	
	int pivot=partition(start,end,arr);
	quicksort(start,pivot-1,arr);
	quicksort(pivot+1,end,arr);
	
}
int main()
{
	string arr;
	cout<<"enter string";
	cin>>arr;
	int n=arr.length();
	quicksort(0,n-1,arr);
	cout<<arr;
	
}