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
	for(ll i=0;i<n-3;i++){
		for(ll j=i+1;j<n-2;j++){
			ll start=j+1;
			ll end=n-1;
			while(start<end){
				ll sum=val[i].first+val[j].first+val[start].first+val[end].first;
				if(sum==target){
					vector<ll> ans(4);
					ans[0]=val[i].second;
					ans[1]=val[j].second;
					ans[2]=val[start].second;
					ans[3]=val[end].second;
					sort(ans.begin(),ans.end());
					cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
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
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
