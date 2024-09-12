#include<iostream>
using namespace std;
int checkRotatedSorted(int arr[],int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
       if(arr[i-1]<arr[i]){
        flag=1;
        
        return flag ;
       }
       else{
        flag=0;
        
        return flag;
       }
    }
}
int main()
{
int n;
    cout<<"enter size of array";
    cin>>n;
    int arr[n];
    cout<<"enter array elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   int flag= checkRotatedSorted(arr,n);
   if(flag==1)
   {
    cout<<"array is sorted or rotated";
   }
   else{
    cout<<"array is not";
   }
}
