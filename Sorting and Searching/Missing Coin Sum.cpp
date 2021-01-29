#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
	ll n;
	cin>>n;
	vector<ll> val(n);
	for(auto &it:val){
		cin>>it;
	}
	sort(val.begin(),val.end());
	ll ans=1;
	for(ll i=0;i<n;i++){
		if(ans<val[i]){
			cout<<ans<<endl;
			return 0;
		}
		else{
			ans+=val[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
