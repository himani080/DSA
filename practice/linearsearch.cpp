#include<iostream>
#include<vector>
using namespace std;
int  linearsearch(int n,int arr[],int key){
    int ans;
   for(int i=0;i<n;i++){
    if(arr[i]==key){
        return 1;
    }
   }  
   return 0;
}

int main(){
    int n;
    cout<<"enter size of array";
    cin>>n;
    int arr[n];
    cout<<"enter elements of array";
   

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
     int key;
    cin>>key;
    int  ans=linearsearch(n,arr,key);
    cout<<ans;
    
}