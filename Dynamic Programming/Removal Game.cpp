#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> val(n);
	for(ll &it:val){
		cin>>it;
	}
	array<ll,2> dp[n][n];
	for(ll gap=0;gap<n;gap++){
		for(ll i=0,j=gap;j<n;i++,j++){
			if(i==j){
				dp[i][j]={val[i],0};
			}
			else{
				if(dp[i+1][j][1]+val[i]>dp[i][j-1][1]+val[j]){
					dp[i][j]={dp[i+1][j][1]+val[i],dp[i+1][j][0]};
				}
				else{
					dp[i][j]={dp[i][j-1][1]+val[j],dp[i][j-1][0]};
				}
			}
		}
	}
	cout<<dp[0][n-1][0]<<endl;
	return 0;
}
