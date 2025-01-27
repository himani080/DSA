#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
void reverse(char s[],int n){
    
        int start=0;
        int e=n-1;
        while(start<e){
           swap(s[start++],s[e--]);
        }
        
    
}
int getlength(char s[])
{
    int count=0;
    for(int i=0;s[i]!='\0';i++)
    {
        count++;
    }
    return count;
}
int main()
{
   
    char s[20];
    cin>>s;
    cout<<"enter string";
    int count=getlength(s);
    reverse(s,count);
           
    cout<<s;
}
