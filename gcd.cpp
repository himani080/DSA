#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter two numbers for which you want gcd";
    cin>>a>>b;
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    cout<<a;
}