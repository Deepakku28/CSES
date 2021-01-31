#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
bool dfs(int index,vector<int> adj[],vector<int> &parent,vector<bool> &visited,int pat,int &startVertex,int &endVertex){
	visited[index]=true;
	parent[index]=pat;
	for(int it:adj[index]){
		if(it==pat){
			continue;
		}
		if(visited[it]==true){
			startVertex=it;
			endVertex=index;
			return true;
		}
		if(visited[it]==false){
			if(dfs(it,adj,parent,visited,index,startVertex,endVertex)==true){
				return true;
			}
		}
	}
	return false;
}
 
int main(){
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
	vector<int> parent(vertex,-1);
	bool flag=false;
	vector<bool> visited(vertex,false);
	int startVertex=-1;
	int endVertex=-1;
	for(int i=0;i<vertex;i++){
		if(visited[i]==false){
			flag=dfs(i,adj,parent,visited,-1,startVertex,endVertex);
		}
		if(flag==true){
			break;
		}
	}
	if(flag==true){
		int start=endVertex;
		vector<int> ans;
		ans.push_back(endVertex);
		while(start!=startVertex){
			start=parent[start];
			ans.push_back(start);
		}
		ans.push_back(endVertex);
		cout<<ans.size()<<endl;
		for(auto it:ans){
			cout<<it+1<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}
