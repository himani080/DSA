#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
void movezeroes(int arr[],int n)
{
    int k=0;
    for(int i=0;i<n;i++)
    {    
        if(arr[i]!=0)
        {
            swap(arr[i],arr[k]);
            k++;
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
    movezeroes(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
