#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	ll target=n*(n+1)/2;
	if(target&1){
		cout<<"0"<<endl;
		return 0;
	}
	target=target/2;
	vector<vector<ll>> dp(n,vector<ll>(target+1,0));
	dp[0][0]=1;
	for(ll i=1;i<n;i++){
		for(ll j=0;j<=target;j++){
			dp[i][j]=dp[i-1][j];
			if(j-i>=0){
				dp[i][j]+=dp[i-1][j-i];
				dp[i][j]%=mod;
			}
		}
	}
	cout<<dp[n-1][target]<<endl;
	return 0;
}
