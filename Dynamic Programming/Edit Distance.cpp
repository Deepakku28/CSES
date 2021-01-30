#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string str;
	string pat;
	cin>>str>>pat;
	ll m=str.size();
	ll n=pat.size();
	vector<vector<ll>> dp(m+1,vector<ll>(n+1,0));
	for(ll i=1;i<=m;i++){
		dp[i][0]=i;
	}
	for(ll i=1;i<=n;i++){
		dp[0][i]=i;
	}
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=n;j++){
			if(str[i-1]==pat[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}
			else{
				dp[i][j]=min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;
			}
		}
	}
	cout<<dp[m][n]<<endl;
	return 0;
}
