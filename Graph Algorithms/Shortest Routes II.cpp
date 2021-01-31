#include<bits/stdc++.h>
using namespace std;
# define ll long long int 
 
int main(){
	ll vertex,edge,query;
	cin>>vertex>>edge>>query;
	vector<vector<ll>> dp(vertex,vector<ll>(vertex,1e15));
	for(ll i=0;i<edge;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		x--,y--;
		dp[x][y]=min(z,dp[x][y]);
		dp[y][x]=min(z,dp[y][x]);
	}
	for(ll k=0;k<vertex;k++){
		for(ll i=0;i<vertex;i++){
			for(ll j=0;j<vertex;j++){
				if(dp[i][j]>dp[i][k]+dp[k][j]){
					dp[i][j]=dp[i][k]+dp[k][j];
				}
			}
		}
	}
	vector<pair<ll,ll>> val(query);
	for(ll i=0;i<query;i++){
		cin>>val[i].first>>val[i].second;
		val[i].first--,val[i].second--;
	}
	for(ll i=0;i<query;i++){
		ll u=val[i].first;
		ll v=val[i].second;
		if(u==v){
			cout<<"0"<<endl;
		}
		else if(dp[u][v]!=1e15){
			cout<<dp[u][v]<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}
