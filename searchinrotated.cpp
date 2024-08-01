#include<iostream>
using namespace std;
int binarysearch(int arr[],int start,int end,int n,int key)
{
     start=0;
     end=n-1;
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(key>arr[mid])
        {
            start=mid+1;
        }
        else if(key<arr[mid])
        {
            end=mid-1;
        }
           mid=start+(end-start)/2;
    }
    return -1;
}
int pivotelement(int arr[],int n)
{
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(arr[mid]>=arr[0])
        {
            return start=mid+1;
        }
        else{
             return end=mid;
        }
    }
    return start;
}
int searchinrotated(int arr[],int n,int key)
{
  int pivotelementt=pivotelement(arr,n);
  if(key<arr[pivotelementt]&&key>arr[n-1]){
    return binarysearch(arr,pivotelementt,n-1,n,key);
      
  }
  else{
    return binarysearch(arr,0,pivotelementt-1,n,key);
  }
}
int main()
{
    int n, key;
    cout<<"enter size of array and key element to search";
    cin>>n>>key;
    
    int arr[n]; 
    cout<<"enter array elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // int index=binarysearch(arr,0,n-1,n,key);
    // cout<<index;
    int searchatindex=searchinrotated(arr,n, key);
    
    cout<<searchatindex;
}
//time complexity=O(LOGN)