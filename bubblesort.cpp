#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool swapped=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=false;
            }
        }
         if(swapped==false){
        break;
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
    bubblesort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
//n-1 rounds
//time complexity=O(n^2)
// best case optimised=o(n)
//worst case optimised=o(n^2)
//space complexoty=O(1)


