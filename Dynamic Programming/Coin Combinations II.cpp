#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,target;
	cin>>n>>target;
	vector<ll> val(n);
	for(ll &it:val){
		cin>>it;
	}
	vector<ll> dp(target+1,0);
	dp[0]=1;
	for(ll j=0;j<n;j++){
		for(ll i=1;i<=target;i++){
			if(i-val[j]>=0){
				dp[i]=dp[i]+dp[i-val[j]];
				if(dp[i]>=mod){
					dp[i]-=mod;
				}
			}
		}
	}
	cout<<dp[target]<<endl;
	return 0;
}
