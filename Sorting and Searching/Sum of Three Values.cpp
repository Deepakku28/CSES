#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,target;
	cin>>n>>target;
	vector<pair<ll,ll>> val(n);
	for(ll i=0;i<n;i++){
		cin>>val[i].first;
		val[i].second=i+1;
	}
	sort(val.begin(),val.end());
	for(ll i=0;i<n-2;i++){
		ll start=i+1;
		ll end=n-1;
		while(start<end){
			ll sum=val[i].first+val[start].first+val[end].first;
			if(sum==target){
				ll ans=val[i].second+val[start].second+val[end].second;
				ll ans1=min({val[i].second,val[start].second,val[end].second});
				ll ans3=max({val[i].second,val[start].second,val[end].second});
				ll ans2=ans-ans1-ans3;
				cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
				return 0;
			}
			else if(sum<target){
				start++;
			}
			else{
				end--;
			}
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
