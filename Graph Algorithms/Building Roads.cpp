#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
void dfs(int index,vector<int> adj[],vector<bool> &visited){
	visited[index]=true;
	for(auto it:adj[index]){
		if(visited[it]==false){
			dfs(it,adj,visited);
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int vertex,edge;
	cin>>vertex>>edge;
	vector<int> adj[vertex];
	for(int i=0;i<edge;i++){
		int src,dest;
		cin>>src>>dest;
		src--,dest--;
		adj[src].push_back(dest);
		adj[dest].push_back(src);
	}
	vector<bool> visited(vertex,false);
	vector<int> ans;
	for(ll i=0;i<vertex;i++){
		if(visited[i]==false){
			ans.push_back(i);
			dfs(i,adj,visited);
		}
	}
	cout<<(int)(ans.size()-1)<<endl;
	for(ll i=0;i<(int)(ans.size()-1);i++){
		cout<<ans[i]+1<<" "<<ans[i+1]+1<<endl;
	}
	return 0;
}
