#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll vertex,edge;
	cin>>vertex>>edge;
	vector<pair<ll,ll>> adj[vertex];
	for(ll i=0;i<edge;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		x--,y--;
		adj[x].push_back({y,z});
	}
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push({0,0});
	vector<ll> dist(vertex,1e15);
	dist[0]=0;
	while(!pq.empty()){
		pair<ll,ll> curr=pq.top();
		pq.pop();
		if(curr.first>dist[curr.second]){
			continue;
		}
		for(auto it:adj[curr.second]){
			if(dist[it.first]>dist[curr.second]+it.second){
				dist[it.first]=dist[curr.second]+it.second;
				pq.push({dist[it.first],it.first});
			}
		}
	}
	for(ll i=0;i<vertex;i++){
		cout<<dist[i]<<" ";
	}
	cout<<endl;
	return 0;
}
