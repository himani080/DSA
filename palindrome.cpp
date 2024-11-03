#include<iostream>
using namespace std;
int reverse(int num){
     int rev=0;
    while(num>0){
       rev=rev*10+num%10;
       num=num/10;

    }
    return rev;
}
int main(){
    int num;
    cout<<"enter a no to check its palindrome or not ";
    cin>>num;
    int rev=reverse(num);
    if(rev==num){
        cout<<"its palindrome";
    }
    else{
        cout<<"its not";
    }
    
}