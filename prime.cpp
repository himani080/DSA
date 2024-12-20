#include<iostream>
#include<vector>
using namespace std;
bool prime(int n){
        if(n==0||n==1){
            return false;
        }
        for(int i=2;i<n;i++){
            if(n%i==0){
                return false;
            }
            
        }
        return true;
     }
int main(){
    int n=100;
     for(int i=0;i<n;i++){
            if(prime(i)){
                cout<<i<<" ";
            }
     }
}