#include<bits/stdc++.h>
using namespace std;
 
void dfs(stack<int> &s,vector<bool> &visited,vector<vector<int>> &adj,int index){
	visited[index]=true;
	for(auto it:adj[index]){
		if(visited[it]==false){
			dfs(s,visited,adj,it);
		}
	}
	s.push(index);
}
 
void dfs1(vector<bool> &visited,vector<int> &ans,int &groupNo,vector<vector<int>> &revAdj,int index){
	visited[index]=true;
	ans[index]=groupNo;
	for(auto it:revAdj[index]){
		if(visited[it]==false){
			dfs1(visited,ans,groupNo,revAdj,it);
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
	stack<int> s;
	vector<bool> visited(vertex,false);
	for(int i=0;i<vertex;i++){
		if(visited[i]==false){
			dfs(s,visited,adj,i);
		}
	}
	for(int i=0;i<vertex;i++){
		visited[i]=false;
	}
	int groupNo=0;
	vector<int> ans(vertex,0);
	while(!s.empty()){
		int val=s.top();
		s.pop();
		if(visited[val]==false){
			groupNo++;
			dfs1(visited,ans,groupNo,revAdj,val);
		}
	}
	cout<<groupNo<<endl;
	for(int i=0;i<vertex;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
