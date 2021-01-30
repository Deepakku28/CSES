#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<pair<ll,ll>> val(n);
	for(ll i=0;i<n;i++){
		cin>>val[i].first>>val[i].second;
	}
	sort(val.begin(),val.end());
	ll ans=0;
	ll value=0;
	for(ll i=0;i<n;i++){
		value+=val[i].first;
		ans+=val[i].second-value;
	}
	cout<<ans<<endl;
	return 0;
}
