#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll INF=1e15;
 
struct info{
	int src;
	int dest;
	int weight;
};
 
int main(){
	ll vertex,edge;
	cin>>vertex>>edge;
	vector<info> adj(edge);
	for(ll i=0;i<edge;i++){
		info temp;
		cin>>temp.src>>temp.dest>>temp.weight;
		temp.src--,temp.dest--;
		adj[i]=temp;
	}
	vector<ll> dist(vertex,INF);
	dist[0]=0;
	vector<ll> relaxant(vertex,-1);
	int x;
	for(ll i=0;i<vertex;i++){
		x=-1;
		for(auto it:adj){
			if(dist[it.dest]>dist[it.src]+it.weight){
				dist[it.dest]=dist[it.src]+it.weight;
				relaxant[it.dest]=it.src;
				x=it.dest;
			}
		}
	}
	if(x==-1){
		cout<<"NO"<<endl;
		return 0;
	}
	for(ll i=0;i<vertex;i++){
		x=relaxant[x];
	}
	vector<ll> cycle;
	ll ver=x;
	cycle.push_back(ver);
	ver=relaxant[x];
	while(ver!=x){
		cycle.push_back(ver);
		ver=relaxant[ver];
	}
	cycle.push_back(x);
	reverse(cycle.begin(),cycle.end());
	cout<<"YES"<<endl;
	for(auto it:cycle){
		cout<<it+1<<" ";
	}
	cout<<endl;
	return 0;
}
