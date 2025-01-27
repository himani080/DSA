#include<iostream>
using namespace std;
void merge(int *arr,int s,int e){
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *arr1=new int[len1];
    int *arr2=new int[len2];
    int mainarrindex=s;
    for(int i=0;i<len1;i++)
    {
      arr1[i]=arr[mainarrindex++];
    }
     mainarrindex=mid+1;
    for(int i=0;i<len2;i++)
    {
      arr2[i]=arr[mainarrindex++];
    }
    int i=0;
    int j=0;
    mainarrindex=s;
    while(i<len1&& j<len2)
    {
        if(arr1[i]<arr2[j]){
            arr[mainarrindex++]=arr1[i++];
        }
        else{
            arr[mainarrindex++]=arr2[j++];
        }
    }
    while(i<len1){
        arr[mainarrindex++]=arr1[i++];
    }
    while(j<len2){
        arr[mainarrindex++]=arr2[j++];
    }
//    delete[]arr1;
//    delete[]arr2;
}
void mergesort(int *arr,int s,int e)
{
    int mid=(s+e)/2;
    //base case
    if(s>=e)
    {
        return;
    }
    //first part sort
    mergesort(arr,s,mid);

    mergesort(arr,mid+1,e);

    merge(arr,s,e);
}
int main()
{
  int n;
    cout<<"enter size of array";
    cin>>n;
   int* arr = new int[n]; 
    cout<<"enter array elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
//space complexity=-O(n)    n/2andn/2=n
// applications:merge sort is usefull in sorting of linked list
//inversion count
//time complexity=O(nlogn)
