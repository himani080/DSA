#include<iostream>
using namespace std;

int main()
{
    int count=0;
    char s[20];
    cin>>s;
    cout<<"enter string";
    for(int i=0;s[i]!='\0';i++)
    {
        count++;
    }

    cout<<count;
}