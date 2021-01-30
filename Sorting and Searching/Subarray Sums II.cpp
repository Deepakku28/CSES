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
	map<ll,ll> mp;
	ll sum=0;
	ll ans=0;
	mp[0]++;
	for(ll i=0;i<n;i++){
		sum+=val[i];
		if(mp.find(sum-target)!=mp.end()){
			ans+=mp[sum-target];
		}
		mp[sum]++;
	}
	cout<<ans<<endl;
	return 0;
}
