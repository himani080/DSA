#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
void reversearray(int arr[],int n)
{
    int start=0;
    int end=n-1;
    for(int i=0;i<end;i++)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
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
    reversearray(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}