#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
 
void topologicalSort(ll index,vector<bool> &visited,vector<ll> &topSort,vector<vector<ll>> &adj,ll &vertex){
	if(index==vertex-1){
		return;
	}
	visited[index]=true;
	for(auto &it:adj[index]){
		if(visited[it]==false){
			topologicalSort(it,visited,topSort,adj,vertex);
		}
	}
	topSort.push_back(index);
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll vertex,edge;
	cin>>vertex>>edge;
	vector<vector<ll>> adj(vertex);
	for(ll i=0;i<edge;i++){
		ll src,dest;
		cin>>src>>dest;
		src--,dest--;
		adj[src].push_back(dest);
	}
	vector<ll> topSort;
	vector<bool> visited(vertex,false);
	for(ll i=0;i<vertex;i++){
		if(visited[i]==false){
			topologicalSort(i,visited,topSort,adj,vertex);
		}
	}
	vector<ll> dp(vertex,0);
	dp[vertex-1]=1;
	for(auto i:topSort){
		for(auto j:adj[i]){
			dp[i]=dp[i]+dp[j];
			if(dp[i]>=mod){
				dp[i]-=mod;
			}
		}
	}
	cout<<dp[0]<<endl;
	return 0;
}
