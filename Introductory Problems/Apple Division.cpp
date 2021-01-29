#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> val(n);
	ll totalSum=0;
	for(ll &it:val){
		cin>>it;
		totalSum+=it;
	}
	ll ans=INT_MAX;
	for(ll mask=0;mask<(1<<n);mask++){
		ll currSum=0;
		for(ll j=0;j<n;j++){
			if((1<<j)&mask){
				currSum+=val[j];
			}
		}
		ans=min(ans,abs(totalSum-2*currSum));
	}
	cout<<ans<<endl;
	return 0;
}
