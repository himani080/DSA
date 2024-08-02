#include<iostream>
using namespace std;
int firstocc(int arr[],int n,int key)
{
    int start=0;
    int end=n-1;
    // int mid=(start+end)/2;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            end=mid-1;            

        }
        else if(key>arr[mid])
        {
             start=mid+1;
        }
        else if(key<arr[mid])
        {
             end=mid-1;
        }
          
    }
    return ans;
}
int lastocc(int arr[],int n,int key)
{
    int start=0;
    int end=n-1;
    // int mid=start+(end-start)/2;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            start=mid+1;            

        }
        else if(key>arr[mid])
        {
             start=mid+1;
        }
        else if(key<arr[mid])
        {
             end=mid-1;
        }
           
    }
    return ans;
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
    int index=firstocc(arr,n,key);
    int index2=lastocc(arr,n,key);
    cout<<"first index is ";
    cout<<index;
    cout<<"last index is ";
    cout<<index2;
    int totalnoocc=(index2-index)+1;
    cout<<"total no of occurances are";
    cout<<totalnoocc;
}
//time complexity=O(LOGN)