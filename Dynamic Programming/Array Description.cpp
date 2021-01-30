#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll mod=1e9+7;
 
int main(){
	ll n,m;
	cin>>n>>m;
	vector<ll> val(n);
	for(ll &it:val){
		cin>>it;
	}
	vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(i==1){
				if(val[i-1]==0 || val[i-1]==j){
					dp[i][j]=1;
				}
			}
			else{
				if(val[i-1]==0 || val[i-1]==j){
					dp[i][j]=((dp[i-1][j-1]+dp[i-1][j])%mod+(j==m?0:dp[i-1][j+1]))%mod;
				}
			}
		}
	}
	ll ans=0;
	for(ll i=1;i<=m;i++){
		ans+=dp[n][i];
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
