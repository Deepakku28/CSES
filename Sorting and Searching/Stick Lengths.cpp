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
	sort(val.begin(),val.end());
	ll target=val[n/2];
	ll ans=0;
	for(ll i=0;i<n;i++){
		ans+=abs(val[i]-target);
	}
	cout<<ans<<endl;
	return 0;
}
