#include<iostream>
#include<string>
using namespace std;
bool palindrome(int i,int j, string str){
    cout<<i<<" "<<j;
    cout<<endl;
    if(i>j)
    {
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
         return palindrome(i+1,j-1,str);
    }
    
}
int main(){
   bool result= palindrome(0,2,"wow");
   cout<<result;
}