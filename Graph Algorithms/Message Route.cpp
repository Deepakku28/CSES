#include<bits/stdc++.h>
using namespace std;
 
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
	vector<int> parent(vertex,-1);
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		auto curr=q.front();
		q.pop();
		for(auto it:adj[curr]){
			if(parent[it]<0){
				parent[it]=curr;
				q.push(it);
			}
		}
	}
	vector<int> ans;
	if(parent[vertex-1]<0){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		int temp=vertex-1;
		while(temp){
			ans.push_back(temp);
			temp=parent[temp];
		}
		ans.push_back(0);
		reverse(ans.begin(),ans.end());
		cout<<ans.size()<<endl;
		for(int i=0;i<(int)ans.size();i++){
			cout<<ans[i]+1<<" ";
		}
	}
	return 0;
}
