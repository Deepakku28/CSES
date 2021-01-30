#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ll n;
	cin>>n;
	vector<ll> val(n);
	for(ll &it:val){
		cin>>it;
	}
	for(ll i=1;i<n;i++){
		val[i]+=val[i-1];
	}
	map<ll,ll> mp;
	mp[0]++;
	ll ans=0;
	for(ll i=0;i<n;i++){
		ll temp=((val[i]%n)+n)%n;
		ans+=mp[temp];
		mp[temp]++;
	}
	cout<<ans<<endl;
	return 0;
}
