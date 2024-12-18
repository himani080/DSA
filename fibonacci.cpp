#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a=0;
    int b=1;
    int n;
    cout<<"enter till which you want series";
    cin>>n;
    // cout<<n;
    cout<<a<<" "<<b<<" ";
    for(int i=0;i<n;i++){
        
        int sum=a+b;
        cout<<sum<<" ";
        a=b;
        b=sum;
    }
    
}
