#include<iostream>
#include<string>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
string reverse(string s){
    int n=s.length();
    int start=0;
    int end=n-1;
    while(start<=end){
        swap(s[start++],s[end--]);
    }
  return s;
}
int main(){
    string s;
    cout<<"enter string";
    cin>>s;
    if(s==reverse(s)){
        cout<<"string is palindrome";
    }
    else{
        cout<<"its not";
    }


}