#include<iostream>
using namespace std;
int binarysearch(int arr[],int n)
{
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start<end)
    {
        if(arr[mid]<arr[mid+1])
        {
            return start=mid+1;

        }
        else{
           return end=mid;
        }
    }
    return start;
}
int main()
{
    int n;
    cout<<"enter size of array and key element to search";
    cin>>n;
    
    int arr[n];
    cout<<"enter array elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int index=binarysearch(arr,n);
    cout<<index;
    cout<<"maximum is "<<arr[index];
}
//time complexity=O(LOGN)
