#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
const ll mod=1e9+7;
const ll INF=1e15;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll vertex,edge;
	cin>>vertex>>edge;
	vector<vector<pair<ll,ll>>> adj(vertex);
	for(ll i=0;i<edge;i++){
		ll src,dest,weight;
		cin>>src>>dest>>weight;
		src--,dest--;
		adj[src].push_back({dest,weight});
	}
	vector<ll> cost(vertex,INF);
	cost[0]=0;
	vector<ll> route(vertex,0);
	route[0]=1;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push({0,0});
	vector<ll> minFlight(vertex,0);
	vector<ll> maxFlight(vertex,0);
	while(!pq.empty()){
		pair<ll,ll> curr=pq.top();
		pq.pop();
		if(curr.first>cost[curr.second]){
			continue;
		}
		for(auto it:adj[curr.second]){
			if(cost[it.first]<curr.first+it.second){
				continue;
			}
			else if(cost[it.first]==curr.first+it.second){
				route[it.first]+=route[curr.second];
				route[it.first]%=mod;
				minFlight[it.first]=min(minFlight[curr.second]+1,minFlight[it.first]);
				maxFlight[it.first]=max(maxFlight[curr.second]+1,maxFlight[it.first]);
			}
			else{
				cost[it.first]=curr.first+it.second;
				route[it.first]=route[curr.second];
				route[it.first]%=mod;
				minFlight[it.first]=minFlight[curr.second]+1;
				maxFlight[it.first]=maxFlight[curr.second]+1;
				pq.push({cost[it.first],it.first});
			}
		}
	}
	cout<<cost[vertex-1]<<" "<<route[vertex-1]<<" "<<minFlight[vertex-1]<<" "<<maxFlight[vertex-1]<<endl;
	return 0;
}
