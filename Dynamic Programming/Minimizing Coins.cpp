#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,target;
	cin>>n>>target;
	vector<ll> val(n);
	for(ll &it:val){
		cin>>it;
	}
	vector<ll> dp(target+1,INT_MAX);
	dp[0]=0;
	for(ll i=1;i<=target;i++){
		for(ll j=0;j<n;j++){
			if(i-val[j]>=0){
				dp[i]=min(dp[i],dp[i-val[j]]+1);
			}
		}
	}
	if(dp[target]==INT_MAX){
		cout<<"-1"<<endl;
	}
	else{
		cout<<dp[target]<<endl;
	}
	return 0;
}
