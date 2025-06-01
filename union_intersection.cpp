#include<vector>
#include<iostream>
using namespace std;
vector<int>unionn(vector<int>&arr1,vector<int>&arr2)
{
    vector<int>ans;
    int i=0;
    int j=0;
    while(i<arr1.size()&&j<arr2.size()){
        
          if(arr1[i]<=arr2[j]){
            if(ans.size()==0|| ans[ans.size()-1]!=arr1[i]){
                ans.push_back(arr1[i]);
                
            }    
            i++;
          }
          else{
            if( ans.size()==0|| ans[ans.size()-1]!=arr2[j]){

                ans.push_back(arr2[j]);
            
            }
            j++;    
          }
    }
    if(i==arr1.size()){
        while(j<arr2.size()){
            if(ans.size()==0|| ans[ans.size()-1]!=arr2[j]){

                ans.push_back(arr2[j]);
                
            }  
            j++;  

        }
    }
    else{
        while(i<arr1.size()){
            if(ans.size()==0|| ans[ans.size()-1]!=arr1[i]){

                ans.push_back(arr1[i]);
                
            }   
            i++; 

        }
    }
    return ans;

}
int main(){
    int input1,input2;
    int m=5;
    int n=6;
    vector<int>arr1,arr2,ans;
    cout<<"enter first arrray elements";
    for(int i=0;i<m;i++){
        cin>>input1;
        arr1.push_back(input1);
    }
    cout<<"enter second array elements";
    for(int i=0;i<n;i++){
        cin>>input2;
        arr2.push_back(input2);
    }
    ans=unionn(arr1,arr2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}