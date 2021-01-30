#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> dp(n+1,0);
	dp[0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=6;j++){
			if(i-j>=0){
				dp[i]=(dp[i]%mod+dp[i-j]%mod)%mod;
			}
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
