#include<iostream>
using namespace std;
int binarysearch(int n)
{
    int ans=-1;

    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(mid*mid==n)
        {
        return mid;
        }
        else if(mid*mid>n){
        end=mid-1;
        }
        else if(mid*mid<n){
        ans=mid;
        start=mid+1;
        }
          mid=start+(end-start)/2;
    }

    return ans;
}
int main(){
    int n;
    cout<<"enter number to find square root of ";
    cin>>n;
   int ans= binarysearch(n);
   cout<<ans;

}