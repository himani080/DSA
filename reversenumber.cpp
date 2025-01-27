#include<iostream>
using namespace std;
int main(){
    int n,rev_no;
    cout<<"enter a no. to reverse";
    cin>>n;
    while(n!=0){
        int remainder=n%10;
        rev_no=rev_no*10+remainder;
        n=n/10;


    }
    cout<<rev_no;

}