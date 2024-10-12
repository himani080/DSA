#include<iostream>
#include<vector>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
vector<int> reverse(vector<int>arr){
    int s=0;
    int e=arr.size()-1;
    while(s<=e){
        swap(arr[s++],arr[e--]);
    }
    return arr;
}
vector <int> sumoftwo(vector<int>&arr1,int n1,vector <int>&arr2,int n2)
{
   vector<int>ans;
   int i=n1-1;
   int j=n2-1;
   int carry=0;
   while(i>=0&&j>=0)
   {
    int value1=arr1[i];
    int value2=arr2[j];
    int sum=value1+value2+carry;
    carry=sum/10;
    sum=sum%10;
    ans.push_back(sum);

    i--;
    j--;
   }
   while(i>=0)
   {
    int sum=arr1[i]+carry;
    carry=sum/10;
    sum=sum%10;
    ans.push_back(sum);
    i--;

   }
   while(j>=0)
   {
    int sum=arr2[j]+carry;
    carry=sum/10;
    sum=sum%10;
    ans.push_back(sum);
    j--;

   }
   while(carry!=0)
   {
    int sum=carry;
    carry=sum/10;
    sum=sum%10;
    ans.push_back(sum);
   } 
   return reverse(ans);
}
int main()
{
    int n1;
    cout<<"enter size of array";
    cin>>n1;
     vector<int>arr1;
    cout<<"enter array elements";
    for(int i=0;i<n1;i++)
    {
        int element;
        cin>>element;
        arr1.push_back(element);
    }
    int n2;
    cout<<"enter size of array";
    cin>>n2;
     vector<int>arr2;
    cout<<"enter array elements for 2nd";
    for(int i=0;i<n2;i++)
    {
        int element;
        cin>>element;
        arr2.push_back(element);
    }
   vector<int>ans= sumoftwo(arr1,n1,arr2,n2);
   for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}