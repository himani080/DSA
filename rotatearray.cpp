#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int>&arr,int k)
{
    int n=arr.size();
    vector<int> temp(n);
    for(int i=0;i<n;i++)
    {
        temp[(i+k)%n]=arr[i];
    }
    arr=temp;

}
int main()
{
     int n, key;
    cout<<"enter size of array and key element to search";
    cin>>n>>key;
    
    vector <int>arr(n);
    cout<<"enter array elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    rotate(arr,key);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
