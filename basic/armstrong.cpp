#include<iostream>
#include<cmath>
using namespace std;
int digits(int num){
    int count=0;
    while(num!=0){

        count++;
        num=num/10;
    }
    return count;
}
int armstrong(int num){
    int n=digits(num);
    int sum=0;
    while(num!=0){
        int remainder=num%10;
       sum=sum+pow(remainder,n);
    //    cout<<pow(remainder,n);
       num=num/10;
    }
   return sum;
}
int main(){
    int num;
    bool result;
    cin>>num;
//    int digit= digits(num);
//     cout<<digit;
    int sum=armstrong(num);
    if(sum==num){
        result=true;
    }
    else{
        result=false;
    }
    cout<<result;
}