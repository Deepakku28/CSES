#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
	ll n;
	cin>>n;
	vector<ll> val(n);
	ll sum=0;
	for(ll &it:val){
		cin>>it;
		sum+=it;
	}
	vector<bool> dp(sum+1,false);
	dp[0]=true;
	for(ll j=0;j<n;j++){
		for(ll i=sum;i>=0;i--){
			if(i-val[j]>=0){
				dp[i]=(dp[i]||dp[i-val[j]]);
			}
		}
	}
	ll count=0;
	for(ll i=1;i<=sum;i++){
		if(dp[i]==true){
			count++;
		}
	}
	cout<<count<<endl;
	for(ll i=1;i<=sum;i++){
		if(dp[i]==true){
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}
