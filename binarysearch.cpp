#include<iostream>
using namespace std;
int binarysearch(int arr[],int n,int key)
{
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(key>arr[mid])
        {
            return start=mid+1;
        }
        else if(key<arr[mid])
        {
            return end=mid-1;
        }
           mid=start+(end-start)/2;
    }
    return -1;
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
    int index=binarysearch(arr,n,key);
    cout<<index;
}
//time complexity=O(LOGN)