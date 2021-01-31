#include<bits/stdc++.h>
using namespace std;
 
void dfs1(int index,vector<int> &visited,vector<vector<int>> &adj,vector<int> &s){
	visited[index]=true;
	for(auto &it:adj[index]){
		if(visited[it]==false){
			dfs1(it,visited,adj,s);
		}
	}
	s.push_back(index);
}
 
void dfs2(int index,vector<vector<int>> &revAdj,int &groupNo,vector<int> &scc){
	scc[index]=groupNo;
	for(auto &it:revAdj[index]){
		if(scc[it]==-1){
			dfs2(it,revAdj,groupNo,scc);
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(2e5),revAdj(2e5);
	for(int i=0;i<n;i++){
		char ch1,ch2;
		int val1,val2;
		cin>>ch1>>val1>>ch2>>val2;
		val1--,val2--;
		val1=val1*2;
		val2=val2*2;
        if(ch1=='-'){
			val1=(val1^1);
		}
        if(ch2=='-'){
			val2=(val2^1);
		}
        adj[val1^1].push_back(val2);
        adj[val2^1].push_back(val1);
        revAdj[val1].push_back(val2^1);
        revAdj[val2].push_back(val1^1);
	}
	vector<int> s;
	vector<int> visited(2e5,false);
	for(int i=0;i<2*m;i++){
		if(visited[i]==false){
			dfs1(i,visited,adj,s);
		}
	}
	vector<int> scc(2e5,-1);
	int groupNo=0;
	for(int i=2*m-1;i>=0;i--){
		if(scc[s[i]]==-1){
			groupNo++;
			dfs2(s[i],revAdj,groupNo,scc);
		}
	}
	vector<char> ans(m,'-');
	for(int i=0;i<m;i++){
		if(scc[2*i]==scc[2*i+1]){
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
		ans[i]=((scc[2*i]>scc[2*i+1])?'+':'-');
	}
	for(auto it:ans){
		cout<<it<<" ";
	}
	return 0;
}
