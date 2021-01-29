#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	map<ll,ll> mp;
	for(ll i=0;i<n;i++){
		ll val;
		cin>>val;
		mp[val]++;
	}
	cout<<mp.size()<<endl;
	return 0;
}
