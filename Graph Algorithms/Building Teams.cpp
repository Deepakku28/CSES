#include<bits/stdc++.h>
using namespace std;
 
bool isBipartite(int index,vector<int> adj[],vector<int> &color,vector<bool> &visited){
	if(color[index]==-1){
		color[index]=0;
	}
	visited[index]=true;
	for(int it:adj[index]){
		if(visited[it]==false){
			color[it]=1-color[index];
			if(isBipartite(it,adj,color,visited)==false){
				return false;
			}
		}
		else if(color[index]==color[it]){
			return false;
		}
	}
	return true;
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
	vector<int> color(vertex,-1);
	bool flag=true;
	vector<bool> visited(vertex,false);
	for(int i=0;i<vertex;i++){
		if(visited[i]==false){
			flag=isBipartite(i,adj,color,visited);
		}
		if(flag==false){
			break;
		}
	}
	if(flag==true){
		for(int i=0;i<vertex;i++){
			cout<<color[i]+1<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}
