#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
const static bool compare(pair<ll,ll> &a,pair<ll,ll> &b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<pair<ll,ll>> val(n);
	for(ll i=0;i<n;i++){
		cin>>val[i].first>>val[i].second;
	}
	sort(val.begin(),val.end(),compare);
	ll i=0,j=1;
	ll ans=1,count=1;
	while(i<n && j<n){
		if(val[i].second<=val[j].first){
			i=j;
			j++;
			count++;
		}
		else{
			j++;
		}
		ans=max(ans,count);
	}
	cout<<ans<<endl;
	return 0;
}
