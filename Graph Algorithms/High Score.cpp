#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
const ll INF=1e15;
const ll NINF=-1e15;
 
struct info{
	ll src;
	ll dest;
	ll weight;
};
 
int main(){
	ll vertex,edge;
	cin>>vertex>>edge;
	vector<info> val(edge);
	for(ll i=0;i<edge;i++){
		cin>>val[i].src>>val[i].dest>>val[i].weight;
		val[i].src--,val[i].dest--;
		val[i].weight*=-1;
	}
	vector<ll> dist(vertex,INF);
	dist[0]=0;
	for(ll i=0;i<vertex-1;i++){
		for(auto it:val){
			ll u=it.src;
			ll v=it.dest;
			ll w=it.weight;
			if(dist[u]==INF){
				continue;
			}
			dist[v]=min(dist[v],dist[u]+w);
			dist[v]=max(dist[v],NINF);
		}
	}
	for(ll i=0;i<vertex-1;i++){
		for(auto it:val){
			ll u=it.src;
			ll v=it.dest;
			ll w=it.weight;
			if(dist[u]==INF){
				continue;
			}
			dist[v]=max(dist[v],NINF);
			if(dist[u]+w<dist[v]){
				dist[v]=NINF;
			}
		}
	}
	if(dist[vertex-1]==NINF){
		cout<<"-1"<<endl;
	}
	else{
		cout<<-1*dist[vertex-1]<<endl;
	}
	return 0;
}
