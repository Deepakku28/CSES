#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll find(vector<ll> &parent,ll &val){
	if(parent[val]==-1){
		return val;
	}
	return parent[val]=find(parent,parent[val]);
}
 
int Union(vector<ll> &parent,ll &x,ll &y){
	x=find(parent,x);
	y=find(parent,y);
	if(x==y){
		return 0;
	}
	parent[x]=y;
	return 1;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll vertex,edge;
	cin>>vertex>>edge;
	array<ll,3> adj[edge];
	for(ll i=0;i<edge;i++){
		cin>>adj[i][1]>>adj[i][2]>>adj[i][0];
		adj[i][1]--,adj[i][2]--;
	}
	sort(adj,adj+edge);
	ll count=0;
	ll ans=0;
	vector<ll> parent(vertex,-1);
	for(ll i=0;i<edge;i++){
		if(Union(parent,adj[i][1],adj[i][2])){
			count++;
			ans+=adj[i][0];
		}
	}
	if(count<vertex-1){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}
