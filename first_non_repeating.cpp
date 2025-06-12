#include<vector>
#include<string>
#include<iostream>
using namespace std;
char non_repeat(string &str){
   bool flag=true;
  for(int i=0;i<str.length();i++){
    for(int j=i+1;j<str.length();j++){
        if(str[i]==str[j]){
            flag=false;
            break;
        } 
    }
    if(flag==false){
        flag=true;
    }
    else{
        return str[i];
    }
  }
}
int main(){
  string str;
  cin>>str;
  char result;
  result=non_repeat(str);
  cout<<result;
}
