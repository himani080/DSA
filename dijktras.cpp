#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int INF=1e9;
int mindistance(vector<int>&dist,vector<bool>&sptset)
{
	int min=INF,min_index;
	for(int v=0;v<dist.size();v++){
		if(!sptset[v]&&dist[v]<=min){
			min=dist[v];
			min_index=v;
		}
	}
	return min_index;
}
void dijktras(const vector<vector<int> > &graph,int src){
	int n=graph.size();
	vector<int>dist(n,INF);
	vector<bool>sptset(n,false);
	dist[src]=0;
	for(int count=0;count<n-1;count++){
		int u=mindistance(dist,sptset);
		sptset[u]=true;
		for(int v=0;v<n;v++){
			if(!sptset[v]&&graph[u][v]&&dist[u]!=INF&&dist[u]+graph[u][v]<dist[v]){
				dist[v]=dist[u]+graph[u][v];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(dist[i]==INF){
			cout<<i;
		}
		else{
			cout<<"distance from"<<i<<"is "<<dist[i];
		}
	}
}
int main()
{

	vector<vector<int> > graph(4, vector<int>(4));
	graph[0][0] = 0; graph[0][1] = 1; graph[0][2] = 4; graph[0][3] = 0;
    graph[1][0] = 1; graph[1][1] = 0; graph[1][2] = 2; graph[1][3] = 6;
    graph[2][0] = 4; graph[2][1] = 2; graph[2][2] = 0; graph[2][3] = 3;
    graph[3][0] = 0; graph[3][1] = 6; graph[3][2] = 3; graph[3][3] = 0;
	int source=0;
	dijktras(graph,source);
	
}

	