#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<string> mat(n);
	for(string &it:mat){
		cin>>it;
	}
	if(mat[0][0]=='*'){
		cout<<"0"<<endl;
		return 0;
	}
	vector<vector<ll>> dp(n,vector<ll>(n,0));
	dp[0][0]=1;
	for(ll i=1;i<n;i++){
		if(mat[i][0]=='.'){
			dp[i][0]=1;
		}
		else{
			break;
		}
	}
	for(ll i=1;i<n;i++){
		if(mat[0][i]=='.'){
			dp[0][i]=1;
		}
		else{
			break;
		}
	}
	for(ll i=1;i<n;i++){
		for(ll j=1;j<n;j++){
			if(mat[i][j]=='.'){
				dp[i][j]+=dp[i-1][j]+dp[i][j-1];
				if(dp[i][j]>=mod){
					dp[i][j]-=mod;
				}
			}
		}
	}
	cout<<dp[n-1][n-1]<<endl;
	return 0;
}
