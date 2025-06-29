#include<iostream>
using namespace std;
int factorial(int n)
{
    int fact=1;
    for(int i=n;i>0;i--){
        fact=fact*i;
    }
    return fact;
}
int permutation(int n,int r){
    int permut=factorial(n)/factorial(n-r);
    return permut;
}
int main(){
    int n,r;
    cin>>n>>r;
    cout<<permutation(n,r);
}
