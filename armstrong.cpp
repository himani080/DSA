#include<iostream>
#include<vector>
using namespace std;
int main(){
    int num;
    vector<int>store;
    cout<<"enter to check armstrong or not";
    cin>>num;
    int originalnum=num;
    int sum=0;
    while(num>0){
        int remainder=num%10;
        num=num/10;
        store.push_back(remainder);

    }
    for(int i=0;i<store.size();i++){
         sum=sum+store[i]*store[i]*store[i];

    }
    if(sum==originalnum){
        cout<<"its armstrong";
    }
    else{
        cout<<"its not";
    }
}