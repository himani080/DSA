#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>&stackinput,int count,int size){
    if(count==size/2){
        stackinput.pop();
        return;
    }

    int num=stackinput.top();
    stackinput.pop();
    solve(stackinput,count+1,size);
    stackinput.push(num);
}
void deletemiddle(stack<int>&stackinput,int size){
      int count=0;
      solve(stackinput,count,size);
}
int main()
{
    stack<int>stackinput;
    int n;
    cout<<"enter size";
    cin>>n;
    cout<<"enter elements";
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        stackinput.push(input);
        
    }
   deletemiddle(stackinput,n);
   while(!stackinput.empty()){
        cout<<stackinput.top();
        stackinput.pop();
   }

}