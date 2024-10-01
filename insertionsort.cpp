#include<iostream>
using namespace std;
void insertionsort(int arr[],int n)
{
   for(int i=1;i<n;i++)
   {
    int temp=arr[i];
    int j=i-1;
    for(;j>=0;j--)
    {
        if(arr[j]>temp)
        {
            arr[j+1]=arr[j];

        }
        else{
            break;
        }
    }
    arr[j+1]=temp;

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

    insertionsort(arr,n);


    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }
    
}
//time complexity=O(n^2)
//BC=TOTAL comparison n-1==O(n)
//WC=1+2+3+4---=n(n-1)/2=O(n^2)
//SPACE=O(1);