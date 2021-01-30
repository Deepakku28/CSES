#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll a,b;
	cin>>a>>b;
	vector<vector<ll>> dp(a+1,vector<ll>(b+1,INT_MAX));
	for(ll i=0;i<=a;i++){
		for(ll j=0;j<=b;j++){
			if(i==j){
				dp[i][j]=0;
			}
			else{
				for(ll k=1;k<i;k++){
					dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
				}
				for(ll k=1;k<j;k++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
				}
			}
		}
	}
	cout<<dp[a][b]<<endl;
	return 0;
}
