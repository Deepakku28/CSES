#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> dp(n+1,INT_MAX);
	dp[0]=0;
	for(ll i=1;i<=n;i++){
		string str=to_string(i);
		for(char ch:str){
			if(i-(ch-'0')>=0){
				dp[i]=min(dp[i],dp[i-(ch-'0')]+1);
			}
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
