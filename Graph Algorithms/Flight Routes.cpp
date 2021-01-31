#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll INF=1e17;
 
int main(){
	ll vertex,edge,k;
	cin>>vertex>>edge>>k;
	vector<vector<pair<ll,ll>>> adj(vertex);
	for(ll i=0;i<edge;i++){
		ll src,dest,weight;
		cin>>src>>dest>>weight;
		src--,dest--;
		adj[src].push_back({dest,weight});
	}
	vector<vector<ll>> dist(vertex,vector<ll>(k,INF));
	dist[0][0]=0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push({0,0});
	while(!pq.empty()){
		pair<ll,ll> curr=pq.top();
		pq.pop();
		ll weight=curr.first;
		ll dest=curr.second;
		if(dist[dest][k-1]<weight){
			continue;
		}
		for(auto it:adj[dest]){
			if(dist[it.first][k-1]>it.second+weight){
				dist[it.first][k-1]=it.second+weight;
				pq.push({dist[it.first][k-1],it.first});
				sort(dist[it.first].begin(),dist[it.first].end());
			}
		}
	}
	for(int i=0;i<k;i++){
		cout<<dist[vertex-1][i]<<" ";
	}
	cout<<endl;
	return 0;
}
