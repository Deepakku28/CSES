#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll vertex,query;
	cin>>vertex>>query;
	vector<vector<ll>> parent(31,vector<ll>(vertex));
	for(ll i=0;i<vertex;i++){
		cin>>parent[0][i];
		parent[0][i]--;
	}
	for(ll i=1;i<30;i++){
		for(ll j=0;j<vertex;j++){
			parent[i][j]=parent[i-1][parent[i-1][j]];
		}
	}
	while(query--){
		ll src,k;
		cin>>src>>k;
		src--;
		for(ll i=0;i<30;i++){
			if((k>>i)&1){
				src=parent[i][src];
			}
		}
		cout<<src+1<<endl; 
	}
	return 0;
}
