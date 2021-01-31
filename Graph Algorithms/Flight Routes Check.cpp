#include<bits/stdc++.h>
using namespace std;
 
void dfs(vector<vector<int>> &adjacency,vector<bool> &visited,int index){
	visited[index]=true;
	for(auto it:adjacency[index]){
		if(visited[it]==false){
			dfs(adjacency,visited,it);
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int vertex,edge;
	cin>>vertex>>edge;
	vector<vector<int>> adj(vertex);
	vector<vector<int>> revAdj(vertex);
	for(int i=0;i<edge;i++){
		int src,dest;
		cin>>src>>dest;
		src--,dest--;
		adj[src].push_back(dest);
		revAdj[dest].push_back(src);
	}
	vector<bool> vis(vertex,false);
	dfs(adj,vis,0);
	vector<bool> revVis(vertex,false);
	dfs(revAdj,revVis,0);
	bool flag=true;
	for(int i=0;i<vertex;i++){
		if(vis[i]==false || revVis[i]==false){
			flag=false;
		}
	}
	if(flag==true){
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
	for(int i=0;i<vertex;i++){
		if(vis[i]==false){
			cout<<"1 "<<i+1<<endl;
			return 0;
		}
	}
	for(int i=0;i<vertex;i++){
		if(revVis[i]==false){
			cout<<i+1<<" 1"<<endl;
			return 0;
		}
	}
	return 0;
}
