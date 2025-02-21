#include<iostream>
using namespace std;
bool issorted(int arr[],int n){
   //base case
   if(n==0||n==1){
    return true;
   }
   if(arr[0]>arr[1]){
    return false;
   }
   else{
     bool remainingpart=issorted(arr+1,n-1);
     return remainingpart;
   }
   
}
int main(){
    int n=6;
    int arr[n]={0,7,4,8,9,6};
    cout<<issorted(arr,n);
}