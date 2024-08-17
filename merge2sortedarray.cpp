#include<iostream>
using namespace std;
void merge(int arr1[],int arr2[],int arr3[],int m,int n){
    int i=0;
    int j=0;
    int k=0;
    while(i<m && j<n)
    {
       if(arr1[i]<arr2[j])
       {
        arr3[k++]=arr1[i++];
    
       }
       else{

        arr3[k++]=arr2[j++];
       
       
       }
    }
    while(i<m)
    {
        arr3[k++]=arr1[i++];
        
       
    }
    while(j<n)
    {
        arr3[k++]=arr2[j++];
      
    }
}
int main(){
    int m;
    cout<<"enter size of array1";
    cin>>m;
    int arr1[m];
    cout<<"enter array elements for array 1";
    for(int i=0;i<m;i++)
    {
        cin>>arr1[i];
    }

    int n;
    cout<<"enter size of array2";
    cin>>n;
    int arr2[n];
    cout<<"enter array elements for array 2";
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    int arr3[m+n];

    merge(arr1,arr2,arr3,m,n);
    for(int i=0;i<m+n;i++)
    {
        cout<<arr3[i]<<" ";
    }

}