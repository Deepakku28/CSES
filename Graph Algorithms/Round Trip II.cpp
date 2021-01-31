#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
void dfs(int index,vector<vector<int>> &adj,vector<bool> &inQueue,vector<int> &parent,vector<bool> &visited){
	visited[index]=true;
	inQueue[index]=true;
	for(int it:adj[index]){
		if(inQueue[it]==true){
			vector<int> ans;
			int start=index;
			ans.push_back(index);
			while(it^start){
				start=parent[start];
				ans.push_back(start);
			}
			ans.push_back(index);
			reverse(ans.begin(),ans.end());
			cout<<ans.size()<<endl;
			for(auto itr:ans){
				cout<<itr+1<<" ";
			}
			cout<<endl;
			exit(0);
		}
		else{
			if(visited[it]==false){
				parent[it]=index;
				dfs(it,adj,inQueue,parent,visited);
			}
		}
	}
	inQueue[index]=false;
}
 
int main(){
	int vertex,edge;
	cin>>vertex>>edge;
	vector<vector<int>> adj(vertex);
	for(int i=0;i<edge;i++){
		int src,dest;
		cin>>src>>dest;
		src--,dest--;
		adj[src].push_back(dest);
	}
	vector<int> parent(vertex,-1);
	vector<bool> visited(vertex,false);
	vector<bool> inQueue(vertex,false);
	for(int i=0;i<vertex;i++){
		if(visited[i]==false){
			dfs(i,adj,inQueue,parent,visited);
		} 
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
