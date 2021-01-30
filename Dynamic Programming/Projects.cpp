#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	array<ll,3> val[n];
	for(ll i=0;i<n;i++){
		cin>>val[i][1]>>val[i][0]>>val[i][2];
	}
	sort(val,val+n);
	set<array<ll,2>> dp;
	dp.insert({0,0});
	ll maxAmount=0;
	for(ll i=0;i<n;i++){
		auto it=dp.lower_bound({val[i][1]});
		it--;
		maxAmount=max(maxAmount,(*it)[1]+val[i][2]);
		dp.insert({val[i][0],maxAmount});
	}
	cout<<maxAmount<<endl;
	return 0;
}
