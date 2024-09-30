#include<iostream>
#include<vector>
using namespace std;
const int V=5;
int minkey(vector<int>& key, vector<bool>mst){
    int min=INT_MAX,min_index;
    for(int i=0;i<V;i++)
    {
        if(!mst[i]&&key[i]<min){
            min=key[i];
            min_index=i;
        }
           
    }
return min_index;
}