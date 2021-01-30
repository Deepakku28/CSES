#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,amount;
	cin>>n>>amount;
	vector<ll> price(n);
	for(ll &it:price){
		cin>>it;
	}
	vector<ll> page(n);
	for(ll &it:page){
		cin>>it;
	}
	vector<ll> dp(amount+1,0);
	for(ll j=0;j<n;j++){
		for(ll i=amount;i>=0;i--){
			if(i-price[j]>=0){
				dp[i]=max(dp[i],dp[i-price[j]]+page[j]);
			}
		}
	}
	cout<<dp[amount]<<endl;
	return 0;
}
