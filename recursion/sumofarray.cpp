#include<iostream>
using namespace std;
int summ(int *arr,int n){
  
    if(n==0){
      return 0;
    }
    if(n==1){
        return arr[0];
    }
   
    int rp=summ(arr+1,n-1);
    int sum=arr[0]+rp;
    return sum;
}
int main(){
    int n=5;
    int arr[n]={2,3,4,5,6};
    int sum=summ(arr,n);
    cout<<sum;
}