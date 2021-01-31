#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int vertex,edge;
	cin>>vertex>>edge;
	vector<vector<int>> adj(vertex);
	for(int i=0;i<edge;i++){
		int src,dest;
		cin>>src>>dest;
		src--,dest--;
		adj[src].push_back(dest);
	}
	vector<int> topologicalSort;
	vector<int> indegree(vertex,0);
	for(int i=0;i<vertex;i++){
		for(auto it:adj[i]){
			indegree[it]++;
		}
	}
	queue<int> q;
	for(int i=0;i<vertex;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int curr=q.front();
		q.pop();
		topologicalSort.push_back(curr);
		for(auto it:adj[curr]){
			indegree[it]--;
			if(indegree[it]==0){
				q.push(it);
			}
		}
	}
	if((int)topologicalSort.size()<vertex){
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	for(auto it:topologicalSort){
		cout<<it+1<<" ";
	}
	cout<<endl;
	return 0;
}
